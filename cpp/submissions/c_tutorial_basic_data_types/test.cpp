#include "problem.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int tests_passed = 0;
int tests_failed = 0;

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
    
    // Simulate input: 3 12345678912345 a 334.23 14049.30493
    stringstream input("3 12345678912345 a 334.23 14049.30493");
    stringstream output;
    
    // Redirect cin and cout
    streambuf* old_cin = cin.rdbuf(input.rdbuf());
    streambuf* old_cout = cout.rdbuf(output.rdbuf());
    
    solution();
    
    // Restore cin and cout
    cin.rdbuf(old_cin);
    cout.rdbuf(old_cout);
    
    string result = output.str();
    
    // Expected output
    string expected = "3\n12345678912345\na\n334.230\n14049.304930000\n";
    
    test("Exact output match", result == expected);
    test("Contains int 3", result.find("3\n") == 0);
    test("Contains long", result.find("12345678912345") != string::npos);
    test("Contains char a", result.find("a\n") != string::npos);
    test("Float has 3 decimals", result.find("334.230") != string::npos);
    test("Double has 9 decimals", result.find("14049.304930000") != string::npos);
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
    
    if (tests_failed == 0) {
        cout << "All tests passed!" << endl;
        return 0;
    } else {
        cout << "Some tests failed!" << endl;
        return 1;
    }
}
