// Day 9: Power Function
// Reference solution (added automatically).

#include <iostream>
using namespace std;

long long power(long long base, int exp) {
    long long result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

int main() {
    long long base;
    int exp;
    cin >> base >> exp;
    cout << power(base, exp) << endl;
    return 0;
}
