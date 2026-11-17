// Day 39: Integer Square Root
// Reference solution (added automatically).

#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;
    long long lo = 0, hi = 2000000000LL, ans = 0;
    while (lo <= hi) {
        long long mid = lo + (hi - lo) / 2;
        if (mid * mid <= n) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}
