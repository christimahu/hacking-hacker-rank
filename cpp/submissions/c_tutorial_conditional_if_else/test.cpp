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
    
    // Test numbers 1-9
    stringstream in1("5"), out1;
    streambuf* old_cin = cin.rdbuf(in1.rdbuf());
    streambuf* old_cout = cout.rdbuf(out1.rdbuf());
    solution();
    cin.rdbuf(old_cin);
    cout.rdbuf(old_cout);
    test("Input 5 outputs 'five'", out1.str() == "five\n");
    coverage.happy_path = true;
    
    stringstream in2("8"), out2;
    cin.rdbuf(in2.rdbuf());
    cout.rdbuf(out2.rdbuf());
    solution();
    cin.rdbuf(old_cin);
    cout.rdbuf(old_cout);
    test("Input 8 outputs 'eight'", out2.str() == "eight\n");
    
    stringstream in3("1"), out3;
    cin.rdbuf(in3.rdbuf());
    cout.rdbuf(out3.rdbuf());
    solution();
    cin.rdbuf(old_cin);
    cout.rdbuf(old_cout);
    test("Input 1 outputs 'one'", out3.str() == "one\n");
    coverage.boundary_min = true;
    
    stringstream in4("9"), out4;
    cin.rdbuf(in4.rdbuf());
    cout.rdbuf(out4.rdbuf());
    solution();
    cin.rdbuf(old_cin);
    cout.rdbuf(old_cout);
    test("Input 9 outputs 'nine'", out4.str() == "nine\n");
    coverage.boundary_max = true;
    
    // Test > 9
    stringstream in5("44"), out5;
    cin.rdbuf(in5.rdbuf());
    cout.rdbuf(out5.rdbuf());
    solution();
    cin.rdbuf(old_cin);
    cout.rdbuf(old_cout);
    test("Input 44 outputs 'Greater than 9'", out5.str() == "Greater than 9\n");
    
    stringstream in6("100"), out6;
    cin.rdbuf(in6.rdbuf());
    cout.rdbuf(out6.rdbuf());
    solution();
    cin.rdbuf(old_cin);
    cout.rdbuf(old_cout);
    test("Input 100 outputs 'Greater than 9'", out6.str() == "Greater than 9\n");
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
