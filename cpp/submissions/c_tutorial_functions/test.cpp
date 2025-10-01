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
    
    // Test sample: 3 4 6 5 -> 6
    stringstream in1("3\n4\n6\n5"), out1;
    streambuf* old_cin = cin.rdbuf(in1.rdbuf());
    streambuf* old_cout = cout.rdbuf(out1.rdbuf());
    solution();
    cin.rdbuf(old_cin);
    cout.rdbuf(old_cout);
    test("Sample: 3 4 6 5 -> 6", out1.str() == "6\n");
    coverage.happy_path = true;
    
    // Test max at first position
    stringstream in2("10\n5\n3\n2"), out2;
    cin.rdbuf(in2.rdbuf());
    cout.rdbuf(out2.rdbuf());
    solution();
    cin.rdbuf(old_cin);
    cout.rdbuf(old_cout);
    test("Max first: 10 5 3 2 -> 10", out2.str() == "10\n");
    
    // Test max at last position
    stringstream in3("1\n2\n3\n100"), out3;
    cin.rdbuf(in3.rdbuf());
    cout.rdbuf(out3.rdbuf());
    solution();
    cin.rdbuf(old_cin);
    cout.rdbuf(old_cout);
    test("Max last: 1 2 3 100 -> 100", out3.str() == "100\n");
    
    // Test all same (duplicates)
    stringstream in4("5\n5\n5\n5"), out4;
    cin.rdbuf(in4.rdbuf());
    cout.rdbuf(out4.rdbuf());
    solution();
    cin.rdbuf(old_cin);
    cout.rdbuf(old_cout);
    test("All same: 5 5 5 5 -> 5", out4.str() == "5\n");
    coverage.special_duplicates = true;
    
    // Test with negative numbers
    stringstream in5("-5\n-2\n-10\n-3"), out5;
    cin.rdbuf(in5.rdbuf());
    cout.rdbuf(out5.rdbuf());
    solution();
    cin.rdbuf(old_cin);
    cout.rdbuf(old_cout);
    test("Negatives: -5 -2 -10 -3 -> -2", out5.str() == "-2\n");
    coverage.edge_negative = true;
    
    // Test with zero
    stringstream in6("0\n-5\n10\n3"), out6;
    cin.rdbuf(in6.rdbuf());
    cout.rdbuf(out6.rdbuf());
    solution();
    cin.rdbuf(old_cin);
    cout.rdbuf(old_cout);
    test("With zero: 0 -5 10 3 -> 10", out6.str() == "10\n");
    coverage.edge_zero = true;
    
    // Test large numbers
    stringstream in7("1000000\n999999\n1000001\n500000"), out7;
    cin.rdbuf(in7.rdbuf());
    cout.rdbuf(out7.rdbuf());
    solution();
    cin.rdbuf(old_cin);
    cout.rdbuf(old_cout);
    test("Large: 1000000 999999 1000001 500000 -> 1000001", out7.str() == "1000001\n");
    coverage.boundary_max = true;
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
