// Day 22: Armstrong Number
// Reference solution (added automatically).

#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;
    int digits = 0;
    for (long long t = n; t > 0; t /= 10) digits++;
    if (n == 0) digits = 1;

    long long sum = 0;
    for (long long t = n; t > 0; t /= 10) {
        long long d = t % 10, p = 1;
        for (int i = 0; i < digits; i++) p *= d;
        sum += p;
    }
    cout << (sum == n ? "Yes" : "No") << endl;
    return 0;
}
