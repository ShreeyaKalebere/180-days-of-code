// Day 38: First and Last Occurrence
// Reference solution (added automatically).

#include <iostream>
#include <vector>
using namespace std;

int findBound(const vector<int>& a, int target, bool first) {
    int lo = 0, hi = (int)a.size() - 1, ans = -1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (a[mid] == target) {
            ans = mid;
            if (first) hi = mid - 1;
            else lo = mid + 1;
        } else if (a[mid] < target) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return ans;
}

int main() {
    int n, target;
    cin >> n >> target;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    cout << findBound(a, target, true) << " " << findBound(a, target, false) << endl;
    return 0;
}
