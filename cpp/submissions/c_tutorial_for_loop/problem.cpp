#include "problem.h"
#include <iostream>

using namespace std;

// BEGIN_SOLUTION
void solution() {
    int a, b;
    cin >> a >> b;
    
    string words[] = {"", "one", "two", "three", "four", "five", 
                      "six", "seven", "eight", "nine"};
    
    for (int i = a; i <= b; i++) {
        if (i <= 9) {
            cout << words[i] << endl;
        } else if (i % 2 == 0) {
            cout << "even" << endl;
        } else {
            cout << "odd" << endl;
        }
    }
}
// END_SOLUTION
