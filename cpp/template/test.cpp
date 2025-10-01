/*
 * test.cpp - Test Suite with Coverage Tracking
 * 
 * WHAT TO EDIT:
 * - The testSolution() function - write tests specific to your problem
 * - Mark coverage flags as you write tests (coverage.happy_path = true, etc.)
 * - Add includes if you need them (e.g., <sstream> for I/O testing)
 * 
 * WHAT NOT TO EDIT:
 * - The test() helper function
 * - The Coverage struct and its methods
 * - The main() structure with test counters
 * - The test summary and coverage report format
 * 
 * HOW TO WRITE TESTS:
 * Use the test() helper: test("description", boolean_condition)
 * Mark coverage after each test category: coverage.happy_path = true;
 * 
 * TESTING PATTERNS:
 * 
 * Pattern 1: Testing a function that returns a value
 *   void testSolution() {
 *       test("Basic case", solution(5) == 10);
 *       coverage.happy_path = true;
 *       
 *       test("Edge case: zero", solution(0) == 0);
 *       coverage.edge_zero = true;
 *   }
 * 
 * Pattern 2: Testing output to stdout (for void functions that print)
 *   void testSolution() {
 *       stringstream buffer;
 *       streambuf* old = cout.rdbuf(buffer.rdbuf());
 *       solution();
 *       cout.rdbuf(old);
 *       string output = buffer.str();
 *       test("Outputs 'Hello'", output == "Hello\n");
 *       coverage.happy_path = true;
 *   }
 * 
 * Pattern 3: Testing with simulated stdin input
 *   void testSolution() {
 *       stringstream input("5 10");
 *       stringstream output;
 *       streambuf* old_cin = cin.rdbuf(input.rdbuf());
 *       streambuf* old_cout = cout.rdbuf(output.rdbuf());
 *       solution();
 *       cin.rdbuf(old_cin);
 *       cout.rdbuf(old_cout);
 *       test("Correct output", output.str() == "15\n");
 *       coverage.happy_path = true;
 *   }
 * 
 * COVERAGE CATEGORIES:
 * - happy_path: Normal expected input (always test this)
 * - edge_empty: Empty input (arrays, strings, etc.)
 * - edge_single: Single element input
 * - edge_zero: Zero values
 * - edge_negative: Negative numbers
 * - boundary_min: Minimum allowed values
 * - boundary_max: Maximum allowed values
 * - special_duplicates: Duplicate values/elements
 * 
 * You don't need to mark ALL categories for every problem - only the ones
 * that are relevant. For example, a string problem might not need edge_negative.
 * 
 * TDD WORKFLOW:
 * 1. Write failing tests first (Red phase)
 * 2. Mark coverage categories for tests you write
 * 3. Implement solution in problem.cpp (Green phase)
 * 4. Run: make test (see test results AND coverage report)
 * 5. Add more tests if coverage is low
 * 6. Refactor if needed
 * 7. When all tests pass, run: make all
 * 
 * COVERAGE INTERPRETATION:
 * - 100%: Excellent - all relevant categories tested
 * - 50-75%: Good - major cases covered
 * - 25-50%: Fair - add more edge/boundary tests
 * - <25%: Weak - need comprehensive testing
 * 
 * Remember: Not all categories apply to all problems. Use judgment!
 */

#include "problem.h"
#include <iostream>
#include <string>

using namespace std;

int tests_passed = 0;
int tests_failed = 0;

// Coverage tracking - DO NOT EDIT THIS STRUCT
struct Coverage {
    bool happy_path = false;        // Normal expected input
    bool edge_empty = false;        // Empty input (arrays, strings)
    bool edge_single = false;       // Single element
    bool edge_zero = false;         // Zero values
    bool edge_negative = false;     // Negative numbers
    bool boundary_min = false;      // Minimum values
    bool boundary_max = false;      // Maximum values
    bool special_duplicates = false; // Duplicate values
    
    int covered() const {
        return happy_path + edge_empty + edge_single + edge_zero + 
               edge_negative + boundary_min + boundary_max + special_duplicates;
    }
    
    int total() const { return 8; }
    
    void report() const {
        cout << "\n========================================" << endl;
        cout << "Test Coverage Report" << endl;
        cout << "========================================" << endl;
        cout << (happy_path ? "[✓]" : "[ ]") << " Happy path (normal input)" << endl;
        cout << (edge_empty ? "[✓]" : "[ ]") << " Edge: Empty input" << endl;
        cout << (edge_single ? "[✓]" : "[ ]") << " Edge: Single element" << endl;
        cout << (edge_zero ? "[✓]" : "[ ]") << " Edge: Zero value" << endl;
        cout << (edge_negative ? "[✓]" : "[ ]") << " Edge: Negative numbers" << endl;
        cout << (boundary_min ? "[✓]" : "[ ]") << " Boundary: Min values" << endl;
        cout << (boundary_max ? "[✓]" : "[ ]") << " Boundary: Max values" << endl;
        cout << (special_duplicates ? "[✓]" : "[ ]") << " Special: Duplicates" << endl;
        cout << "\nCoverage: " << covered() << "/" << total() 
             << " (" << (covered() * 100 / total()) << "%)" << endl;
        
        if (covered() == 0) {
            cout << "\nWARNING: No coverage marked! Remember to set coverage flags." << endl;
        } else if (covered() < 3) {
            cout << "\nSuggestion: Consider adding more test categories for robustness." << endl;
        }
    }
} coverage;

// Helper function - DO NOT EDIT
void test(const string& name, bool condition) {
    if (condition) {
        cout << "[PASS] " << name << endl;
        tests_passed++;
    } else {
        cout << "[FAIL] " << name << endl;
        tests_failed++;
    }
}

// EDIT THIS FUNCTION: Write your tests here and mark coverage
void testSolution() {
    cout << "=== Testing solution ===" << endl;
    
    // This is a placeholder failing test - replace with real tests
    test("Known failure", 0 == 1);
    
    // EXAMPLE: How to write tests with coverage tracking
    // 
    // test("Normal case", solution(5) == 10);
    // coverage.happy_path = true;
    //
    // test("Zero value", solution(0) == 0);
    // coverage.edge_zero = true;
    //
    // test("Negative value", solution(-5) == -10);
    // coverage.edge_negative = true;
    //
    // test("Large value", solution(1000000) == 2000000);
    // coverage.boundary_max = true;
}

// DO NOT EDIT BELOW - Test harness with coverage reporting
int main() {
    cout << "========================================" << endl;
    cout << "Running Test Suite" << endl;
    cout << "========================================" << endl;
    
    testSolution();
    
    cout << "========================================" << endl;
    cout << "Test Summary" << endl;
    cout << "========================================" << endl;
    cout << "Passed: " << tests_passed << endl;
    cout << "Failed: " << tests_failed << endl;
    cout << "Total:  " << (tests_passed + tests_failed) << endl;
    
    coverage.report();
    
    if (tests_failed == 0) {
        cout << "\nAll tests passed!" << endl;
        return 0;
    } else {
        cout << "\nSome tests failed!" << endl;
        return 1;
    }
}
