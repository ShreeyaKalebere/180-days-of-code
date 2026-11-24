// Day 45: Count Inversions
// Reference solution (added automatically).

#include <iostream>
#include <vector>
using namespace std;

long long sortCount(vector<int>& a, int lo, int hi) {
    if (lo >= hi) return 0;
    int mid = lo + (hi - lo) / 2;
    long long count = sortCount(a, lo, mid) + sortCount(a, mid + 1, hi);
    vector<int> tmp;
    int i = lo, j = mid + 1;
    while (i <= mid && j <= hi) {
        if (a[i] <= a[j]) tmp.push_back(a[i++]);
        else {
            count += mid - i + 1;
            tmp.push_back(a[j++]);
        }
    }
    while (i <= mid) tmp.push_back(a[i++]);
    while (j <= hi) tmp.push_back(a[j++]);
    for (int k = 0; k < (int)tmp.size(); k++) a[lo + k] = tmp[k];
    return count;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    cout << sortCount(a, 0, n - 1) << endl;
    return 0;
}
