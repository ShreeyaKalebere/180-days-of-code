// Day 36: Linear Search
// Reference solution (added automatically).

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, target;
    cin >> n >> target;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    for (int i = 0; i < n; i++) {
        if (a[i] == target) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
