// Day 49: Remove Duplicates from a Sorted Array
// Reference solution (added automatically).

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;

    int k = 0;
    for (int i = 0; i < n; i++) {
        if (k == 0 || a[i] != a[k - 1]) a[k++] = a[i];
    }
    cout << k << "\n";
    for (int i = 0; i < k; i++) cout << a[i] << (i + 1 < k ? " " : "\n");
    return 0;
}
