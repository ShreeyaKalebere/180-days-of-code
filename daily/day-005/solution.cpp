// Day 5: Grade Calculator
// Reference solution (added automatically).

#include <iostream>
using namespace std;

int main() {
    int marks;
    cin >> marks;
    if (marks >= 90) cout << "A";
    else if (marks >= 75) cout << "B";
    else if (marks >= 60) cout << "C";
    else if (marks >= 40) cout << "D";
    else cout << "F";
    cout << endl;
    return 0;
}
