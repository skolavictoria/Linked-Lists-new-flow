#!/usr/bin/env python3
"""
Sample test file to demonstrate how tests should be structured.
Replace this with your actual assignment tests.
"""

import pytest

def test_sample_passing_test():
    """A sample test that always passes"""
    assert True

def test_sample_calculation():
    """A sample test that checks a calculation"""
    # Replace with actual tests for student code
    result = 2 + 2
    assert result == 4, f"Expected 4, got {result}"

@pytest.mark.parametrize("input_val,expected", [
    (1, 1),
    (2, 4),
    (3, 9),
    (4, 16),
])
def test_sample_parametrized(input_val, expected):
    """A sample parametrized test"""
    # Replace with actual tests for student code
    result = input_val ** 2
    assert result == expected, f"Expected {expected}, got {result}"

# Add more tests specific to your assignment
