// Day 14: Count and Sum of Digits
// Reference solution (added automatically).

#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;
    if (n == 0) {
        cout << "1 0" << endl;
        return 0;
    }
    int digits = 0;
    long long sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
        digits++;
    }
    cout << digits << " " << sum << endl;
    return 0;
}
