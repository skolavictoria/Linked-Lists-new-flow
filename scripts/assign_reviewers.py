#!/usr/bin/env python3
"""
Script to assign peer reviewers when the deadline arrives.
This script is triggered by the GitHub Actions workflow at the deadline.
"""

import json
import os
import random
import datetime
from github import Github

def load_review_pool():
    """Load the current review pool"""
    try:
        with open('review_pool.json', 'r') as f:
            return json.load(f)
    except (FileNotFoundError, json.JSONDecodeError):
        print("Error: review_pool.json not found or invalid")
        return None

def assign_reviewers(students, num_reviewers=3):
    """
    Assign reviewers to each student
    
    Args:
        students: List of student names
        num_reviewers: Number of reviewers to assign per student
    
    Returns:
        Dictionary mapping each student to their assigned reviewers
    """
    assignments = {}
    
    if len(students) < num_reviewers + 1:
        print(f"Warning: Not enough students ({len(students)}) to assign {num_reviewers} reviewers")
        num_reviewers = min(num_reviewers, len(students) - 1)
    
    for student in students:
        # Create a list of potential reviewers (everyone except the student)
        potential_reviewers = [s for s in students if s != student]
        
        # Randomly select reviewers
        if len(potential_reviewers) >= num_reviewers:
            reviewers = random.sample(potential_reviewers, num_reviewers)
        else:
            reviewers = potential_reviewers
        
        assignments[student] = reviewers
    
    return assignments

def create_review_issues(assignments):
    """Create GitHub issues for each review assignment"""
    token = os.environ.get('GITHUB_TOKEN')
    if not token:
        print("Error: GITHUB_TOKEN not set")
        return False
    
    g = Github(token)
    repo = g.get_repo(os.environ.get('GITHUB_REPOSITORY'))
    
    for student, reviewers in assignments.items():
        # Create an issue for each reviewer
        for reviewer in reviewers:
            issue_title = f"Review Assignment: {reviewer} to review {student}"
            issue_body = f"""
# Review Assignment

@{reviewer} has been assigned to review @{student}'s submission.

## Instructions
1. Review the code in the branch `dev-{student}`
2. Create a new file named `review-for-{student}.md` in the `reviews` directory
3. Submit your review by creating a pull request from your branch to `dev-{student}`

## Deadline
Please complete your review within one week.

## Review Guidelines
- Be constructive and respectful
- Comment on code quality, structure, and functionality
- Suggest improvements
- Highlight good practices you observed
            """
            
            repo.create_issue(
                title=issue_title,
                body=issue_body,
                assignees=[reviewer]
            )
    
    return True

def save_assignments(assignments):
    """Save the review assignments to a JSON file"""
    # Create reviews directory if it doesn't exist
    os.makedirs('reviews', exist_ok=True)
    
    assignment_data = {
        "assignments": assignments,
        "generated_at": datetime.datetime.now().isoformat(),
        "metadata": {
            "description": "Peer review assignments"
        }
    }
    
    with open('reviews/assignments.json', 'w') as f:
        json.dump(assignment_data, f, indent=2)

def main():
    """Main function to assign reviewers"""
    review_pool = load_review_pool()
    if not review_pool:
        return False
    
    students = review_pool.get("students", [])
    if not students:
        print("No students in review pool")
        return False
    
    # Assign reviewers
    assignments = assign_reviewers(students)
    
    # Save assignments
    save_assignments(assignments)
    
    # Create GitHub issues
    create_review_issues(assignments)
    
    return True

if __name__ == "__main__":
    success = main()
    if not success:
        exit(1)
