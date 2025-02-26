#!/usr/bin/env python3
"""
Test file for C++ linked list implementation assignment.

This file contains automated tests to evaluate student implementations of a linked list.
The tests verify correctness, memory management, edge case handling, and performance.

Students should NOT modify this file. Their implementation should conform to the
requirements specified in the README.md file.
"""

import pytest
import subprocess
import os
import re
import platform

# Determine the correct command based on the OS
if platform.system() == "Windows":
    COMPILE_CMD = "g++ -std=c++17 -o {executable} {source_files}"
    RUN_CMD = "{executable}"
else:
    COMPILE_CMD = "g++ -std=c++17 -o {executable} {source_files}"
    RUN_CMD = "./{executable}"

# Path constants - these match the required project structure
SRC_DIR = "src"
LINKED_LIST_H = os.path.join(SRC_DIR, "linked_list.h")
LINKED_LIST_CPP = os.path.join(SRC_DIR, "linked_list.cpp")
MAIN_CPP = "main.cpp"

# Test executable name
TEST_EXECUTABLE = "test_linked_list"

# Test helper functions
def compile_test_program(test_code, executable_name=TEST_EXECUTABLE):
    """
    Compile a test program with the student's linked list implementation.
    
    This function creates a temporary C++ file with test code, then compiles it
    along with the student's implementation.
    
    Args:
        test_code: C++ code to test the linked list implementation
        executable_name: Name for the compiled executable
        
    Returns:
        bool: True if compilation succeeded, False otherwise
    """
    # Create a temporary test file
    with open("temp_test.cpp", "w") as f:
        f.write(test_code)
    
    # Compile the test program
    source_files = f"temp_test.cpp {LINKED_LIST_CPP}"
    cmd = COMPILE_CMD.format(executable=executable_name, source_files=source_files)
    
    result = subprocess.run(cmd, shell=True, capture_output=True, text=True)
    
    # Check if compilation was successful
    if result.returncode != 0:
        print(f"Compilation error: {result.stderr}")
        return False
    
    return True

def run_test_program(executable_name=TEST_EXECUTABLE):
    """
    Run the compiled test program and return its output.
    
    Args:
        executable_name: Name of the executable to run
        
    Returns:
        tuple: (stdout, stderr, return_code) from the executed program
    """
    cmd = RUN_CMD.format(executable=executable_name)
    result = subprocess.run(cmd, shell=True, capture_output=True, text=True)
    return result.stdout, result.stderr, result.returncode

# Fixture to check if required files exist
@pytest.fixture(scope="session")
def check_files():
    """
    Check if the required files exist in the expected directory structure.
    
    Returns:
        list: List of missing files/directories
    """
    missing_files = []
    
    if not os.path.exists(SRC_DIR):
        os.makedirs(SRC_DIR)
        missing_files.append(SRC_DIR)
    
    if not os.path.exists(LINKED_LIST_H):
        missing_files.append(LINKED_LIST_H)
    
    if not os.path.exists(LINKED_LIST_CPP):
        missing_files.append(LINKED_LIST_CPP)
    
    return missing_files

# Test if required files exist
def test_required_files_exist(check_files):
    """
    Test if all required files exist in the correct structure.
    
    This ensures students have created the necessary files in the right locations.
    """
    missing_files = check_files
    assert not missing_files, f"Missing required files: {', '.join(missing_files)}"

# Test if the LinkedList class has all required methods
def test_class_has_required_methods():
    """
    Test if the LinkedList class has all required methods with correct signatures.
    
    This test parses the header file to check for required method declarations.
    """
    # Read the header file
    with open(LINKED_LIST_H, "r") as f:
        header_content = f.read()
    
    # Required methods to check
    required_methods = [
        r"void\s+insertAtBeginning\s*\(\s*int\s+value\s*\)",
        r"void\s+insertAtEnd\s*\(\s*int\s+value\s*\)",
        r"void\s+insertAtPosition\s*\(\s*int\s+value\s*,\s*int\s+position\s*\)",
        r"bool\s+deleteFromBeginning\s*\(\s*\)",
        r"bool\s+deleteFromEnd\s*\(\s*\)",
        r"bool\s+deleteFromPosition\s*\(\s*int\s+position\s*\)",
        r"bool\s+deleteValue\s*\(\s*int\s+value\s*\)",
        r"int\s+getSize\s*\(\s*\)",
        r"bool\s+isEmpty\s*\(\s*\)",
        r"void\s+display\s*\(\s*\)",
        r"Node\s*\*\s*search\s*\(\s*int\s+value\s*\)",
        r"void\s+reverse\s*\(\s*\)",
        r"void\s+sort\s*\(\s*\)",
        r"void\s+removeDuplicates\s*\(\s*\)",
        r"Node\s*\*\s*getMiddleNode\s*\(\s*\)",
        r"bool\s+detectLoop\s*\(\s*\)",
        r"void\s+clear\s*\(\s*\)"
    ]
    
    missing_methods = []
    for method in required_methods:
        if not re.search(method, header_content):
            missing_methods.append(method.split(r"\s+")[1].split(r"\s*")[0])
    
    assert not missing_methods, f"Missing required methods: {', '.join(missing_methods)}"

# Test basic operations
def test_basic_operations():
    """
    Test basic linked list operations.
    
    This test verifies:
    - isEmpty and getSize on empty list
    - insertAtBeginning
    - insertAtEnd
    - insertAtPosition
    - deleteFromBeginning
    - deleteFromEnd
    - deleteFromPosition
    - deleteValue
    - clear
    """
    test_code = """
    #include <iostream>
    #include <cassert>
    #include "src/linked_list.h"
    
    int main() {
        LinkedList list;
        
        // Test isEmpty on empty list
        assert(list.isEmpty() == true);
        assert(list.getSize() == 0);
        
        // Test insertAtBeginning
        list.insertAtBeginning(10);
        assert(list.isEmpty() == false);
        assert(list.getSize() == 1);
        
        // Test insertAtEnd
        list.insertAtEnd(20);
        assert(list.getSize() == 2);
        
        // Test insertAtPosition
        list.insertAtPosition(15, 1);
        assert(list.getSize() == 3);
        
        // Test deleteFromBeginning
        assert(list.deleteFromBeginning() == true);
        assert(list.getSize() == 2);
        
        // Test deleteFromEnd
        assert(list.deleteFromEnd() == true);
        assert(list.getSize() == 1);
        
        // Test deleteFromPosition
        list.insertAtBeginning(5);
        assert(list.deleteFromPosition(0) == true);
        assert(list.getSize() == 1);
        
        // Test deleteValue
        list.insertAtEnd(25);
        assert(list.deleteValue(15) == true);
        assert(list.getSize() == 1);
        
        // Test clear
        list.clear();
        assert(list.isEmpty() == true);
        assert(list.getSize() == 0);
        
        std::cout << "All basic operations tests passed!" << std::endl;
        return 0;
    }
    """
    
    assert compile_test_program(test_code, "test_basic_ops"), "Failed to compile basic operations test"
    stdout, stderr, returncode = run_test_program("test_basic_ops")
    assert returncode == 0, f"Basic operations test failed with error: {stderr}"
    assert "All basic operations tests passed!" in stdout, "Basic operations test did not pass"

# Test advanced operations
def test_advanced_operations():
    """
    Test advanced linked list operations.
    
    This test verifies:
    - search
    - reverse
    - sort
    - removeDuplicates
    - getMiddleNode
    - detectLoop
    """
    test_code = """
    #include <iostream>
    #include <cassert>
    #include <vector>
    #include "src/linked_list.h"
    
    int main() {
        LinkedList list;
        
        // Test search
        list.insertAtEnd(10);
        list.insertAtEnd(20);
        list.insertAtEnd(30);
        
        Node* found = list.search(20);
        assert(found != nullptr);
        assert(found->data == 20);
        
        Node* not_found = list.search(25);
        assert(not_found == nullptr);
        
        // Test reverse
        list.reverse();
        // After reverse: 30 -> 20 -> 10
        Node* first = list.search(30);
        assert(first != nullptr);
        
        // Test sort
        list.clear();
        list.insertAtEnd(30);
        list.insertAtEnd(10);
        list.insertAtEnd(20);
        list.sort();
        // After sort: 10 -> 20 -> 30
        Node* smallest = list.search(10);
        assert(smallest != nullptr);
        
        // Test removeDuplicates
        list.clear();
        list.insertAtEnd(10);
        list.insertAtEnd(20);
        list.insertAtEnd(10);
        list.insertAtEnd(30);
        list.insertAtEnd(20);
        list.removeDuplicates();
        assert(list.getSize() == 3);
        
        // Test getMiddleNode
        list.clear();
        list.insertAtEnd(10);
        list.insertAtEnd(20);
        list.insertAtEnd(30);
        Node* middle = list.getMiddleNode();
        assert(middle != nullptr);
        assert(middle->data == 20);
        
        // Test detectLoop
        list.clear();
        list.insertAtEnd(10);
        list.insertAtEnd(20);
        assert(list.detectLoop() == false);
        
        std::cout << "All advanced operations tests passed!" << std::endl;
        return 0;
    }
    """
    
    assert compile_test_program(test_code, "test_adv_ops"), "Failed to compile advanced operations test"
    stdout, stderr, returncode = run_test_program("test_adv_ops")
    assert returncode == 0, f"Advanced operations test failed with error: {stderr}"
    assert "All advanced operations tests passed!" in stdout, "Advanced operations test did not pass"

# Test edge cases
def test_edge_cases():
    """
    Test edge cases for linked list operations.
    
    This test verifies behavior with:
    - Empty lists
    - Invalid positions
    - Out-of-bounds operations
    """
    test_code = """
    #include <iostream>
    #include <cassert>
    #include "src/linked_list.h"
    
    int main() {
        LinkedList list;
        
        // Test operations on empty list
        assert(list.deleteFromBeginning() == false);
        assert(list.deleteFromEnd() == false);
        assert(list.deleteFromPosition(0) == false);
        assert(list.deleteValue(10) == false);
        assert(list.search(10) == nullptr);
        assert(list.getMiddleNode() == nullptr);
        assert(list.detectLoop() == false);
        
        // Test operations with invalid positions
        list.insertAtBeginning(10);
        assert(list.deleteFromPosition(1) == false);
        assert(list.deleteFromPosition(-1) == false);
        
        list.insertAtPosition(20, 100); // Should handle out-of-bounds position
        assert(list.getSize() <= 2);
        
        std::cout << "All edge cases tests passed!" << std::endl;
        return 0;
    }
    """
    
    assert compile_test_program(test_code, "test_edge_cases"), "Failed to compile edge cases test"
    stdout, stderr, returncode = run_test_program("test_edge_cases")
    assert returncode == 0, f"Edge cases test failed with error: {stderr}"
    assert "All edge cases tests passed!" in stdout, "Edge cases test did not pass"

# Test performance with large lists
def test_performance():
    """
    Test performance with large lists.
    
    This test verifies:
    - Performance with large number of elements
    - Efficiency of search operations
    - Efficiency of sort operations
    """
    test_code = """
    #include <iostream>
    #include <cassert>
    #include <chrono>
    #include "src/linked_list.h"
    
    int main() {
        LinkedList list;
        const int SIZE = 1000;
        
        // Insert many elements
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < SIZE; i++) {
            list.insertAtEnd(i);
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        
        std::cout << "Time to insert " << SIZE << " elements: " << duration << "ms" << std::endl;
        assert(list.getSize() == SIZE);
        
        // Search for elements
        start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < SIZE; i += 100) {
            Node* found = list.search(i);
            assert(found != nullptr);
            assert(found->data == i);
        }
        end = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        
        std::cout << "Time to search for elements: " << duration << "ms" << std::endl;
        
        // Sort the list
        start = std::chrono::high_resolution_clock::now();
        list.sort();
        end = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        
        std::cout << "Time to sort " << SIZE << " elements: " << duration << "ms" << std::endl;
        
        std::cout << "All performance tests passed!" << std::endl;
        return 0;
    }
    """
    
    assert compile_test_program(test_code, "test_performance"), "Failed to compile performance test"
    stdout, stderr, returncode = run_test_program("test_performance")
    assert returncode == 0, f"Performance test failed with error: {stderr}"
    assert "All performance tests passed!" in stdout, "Performance test did not pass"

# Clean up after tests
def test_cleanup():
    """
    Clean up temporary files created during testing.
    
    This should be run after all other tests to remove temporary files.
    """
    # Remove temporary files
    for file in ["temp_test.cpp", TEST_EXECUTABLE, "test_basic_ops", "test_adv_ops", "test_edge_cases", "test_performance"]:
        if os.path.exists(file):
            os.remove(file)
    
    # On Windows, also remove .exe files
    if platform.system() == "Windows":
        for file in [f"{TEST_EXECUTABLE}.exe", "test_basic_ops.exe", "test_adv_ops.exe", "test_edge_cases.exe", "test_performance.exe"]:
            if os.path.exists(file):
                os.remove(file)
