// Day 37: Binary Search
// Reference solution (added automatically).

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, target;
    cin >> n >> target;
    vector<int> a(n);
    for (auto& x : a) cin >> x;

    int lo = 0, hi = n - 1, ans = -1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (a[mid] == target) { ans = mid; break; }
        if (a[mid] < target) lo = mid + 1;
        else hi = mid - 1;
    }
    cout << ans << endl;
    return 0;
}
