// Day 19: Decimal to Binary
// Reference solution (added automatically).

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    long long n;
    cin >> n;
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    string bits;
    while (n > 0) {
        bits += char('0' + n % 2);
        n /= 2;
    }
    reverse(bits.begin(), bits.end());
    cout << bits << endl;
    return 0;
}
