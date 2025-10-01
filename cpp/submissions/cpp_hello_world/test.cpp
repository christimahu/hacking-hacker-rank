#include "problem.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int tests_passed = 0;
int tests_failed = 0;

struct Coverage {
    bool happy_path = false;
    bool edge_empty = false;
    bool edge_single = false;
    bool edge_zero = false;
    bool edge_negative = false;
    bool boundary_min = false;
    bool boundary_max = false;
    bool special_duplicates = false;
    
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
            cout << "\nWARNING: No coverage marked!" << endl;
        }
    }
} coverage;

void test(const string& name, bool condition) {
    if (condition) {
        cout << "[PASS] " << name << endl;
        tests_passed++;
    } else {
        cout << "[FAIL] " << name << endl;
        tests_failed++;
    }
}

void testSolution() {
    cout << "=== Testing solution ===" << endl;
    
    stringstream buffer;
    streambuf* old = cout.rdbuf(buffer.rdbuf());
    
    solution();
    
    cout.rdbuf(old);
    string output = buffer.str();
    
    test("Outputs 'Hello, World!'", output == "Hello, World!\n");
    test("Contains 'Hello'", output.find("Hello") != string::npos);
    test("Contains 'World'", output.find("World") != string::npos);
    test("Has comma", output.find(",") != string::npos);
    coverage.happy_path = true;
}

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
