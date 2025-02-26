#!/usr/bin/env python3
"""
Script to update the review_pool.json file when a student passes all tests.
This script is triggered by the GitHub Actions workflow when tests pass.
"""

import json
import os
import datetime
import re

def get_student_name_from_branch():
    """Extract student name from branch name (dev-student-name)"""
    branch_name = os.environ.get('BRANCH_NAME', '')
    match = re.match(r'dev-(.*)', branch_name)
    if match:
        return match.group(1)
    return None

def update_review_pool():
    """Update the review_pool.json file with the student who passed tests"""
    student_name = get_student_name_from_branch()
    if not student_name:
        print("Could not extract student name from branch")
        return False
    
    # Load current review pool
    try:
        with open('review_pool.json', 'r') as f:
            review_pool = json.load(f)
    except (FileNotFoundError, json.JSONDecodeError):
        # Initialize if file doesn't exist or is invalid
        review_pool = {
            "students": [],
            "last_updated": "",
            "metadata": {
                "description": "This file tracks students who have passed all tests and are eligible for peer review",
                "format_version": "1.0"
            }
        }
    
    # Add student if not already in the pool
    if student_name not in review_pool["students"]:
        review_pool["students"].append(student_name)
        review_pool["last_updated"] = datetime.datetime.now().isoformat()
        
        # Save updated review pool
        with open('review_pool.json', 'w') as f:
            json.dump(review_pool, f, indent=2)
        
        print(f"Added {student_name} to review pool")
        return True
    else:
        print(f"{student_name} is already in review pool")
        return True

if __name__ == "__main__":
    success = update_review_pool()
    if not success:
        exit(1)
