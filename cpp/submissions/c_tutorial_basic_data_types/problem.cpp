#include "problem.h"
#include <iostream>
#include <iomanip>

using namespace std;

// BEGIN_SOLUTION
void solution() {
    int i;
    long l;
    char c;
    float f;
    double d;
    
    cin >> i >> l >> c >> f >> d;
    
    cout << i << endl;
    cout << l << endl;
    cout << c << endl;
    cout << fixed << setprecision(3) << f << endl;
    cout << fixed << setprecision(9) << d << endl;
}
// END_SOLUTION
