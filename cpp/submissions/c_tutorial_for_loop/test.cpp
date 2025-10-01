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
    
    // Test sample input: 8 to 11
    stringstream in1("8\n11"), out1;
    streambuf* old_cin = cin.rdbuf(in1.rdbuf());
    streambuf* old_cout = cout.rdbuf(out1.rdbuf());
    solution();
    cin.rdbuf(old_cin);
    cout.rdbuf(old_cout);
    test("Sample: 8 to 11", out1.str() == "eight\nnine\neven\nodd\n");
    coverage.happy_path = true;
    
    // Test single number (edge case)
    stringstream in2("5\n5"), out2;
    cin.rdbuf(in2.rdbuf());
    cout.rdbuf(out2.rdbuf());
    solution();
    cin.rdbuf(old_cin);
    cout.rdbuf(old_cout);
    test("Single number: 5 to 5", out2.str() == "five\n");
    coverage.edge_single = true;
    
    // Test boundary: 1 to 9 (all words)
    stringstream in3("1\n9"), out3;
    cin.rdbuf(in3.rdbuf());
    cout.rdbuf(out3.rdbuf());
    solution();
    cin.rdbuf(old_cin);
    cout.rdbuf(old_cout);
    test("All words: 1 to 9", out3.str() == "one\ntwo\nthree\nfour\nfive\nsix\nseven\neight\nnine\n");
    coverage.boundary_min = true;
    
    // Test transition from words to even/odd
    stringstream in4("9\n12"), out4;
    cin.rdbuf(in4.rdbuf());
    cout.rdbuf(out4.rdbuf());
    solution();
    cin.rdbuf(old_cin);
    cout.rdbuf(old_cout);
    test("Transition: 9 to 12", out4.str() == "nine\neven\nodd\neven\n");
    coverage.boundary_max = true;
    
    // Test larger numbers (all even/odd)
    stringstream in5("10\n13"), out5;
    cin.rdbuf(in5.rdbuf());
    cout.rdbuf(out5.rdbuf());
    solution();
    cin.rdbuf(old_cin);
    cout.rdbuf(old_cout);
    test("Large numbers: 10 to 13", out5.str() == "even\nodd\neven\nodd\n");
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
