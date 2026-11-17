// Day 20: Binary to Decimal
// Reference solution (added automatically).

#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    long long value = 0;
    for (char c : s) {
        value = value * 2 + (c - '0');
    }
    cout << value << endl;
    return 0;
}
