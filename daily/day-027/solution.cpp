// Day 27: Move Zeros to the End
// Reference solution (added automatically).

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;

    int write = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != 0) swap(a[write++], a[i]);
    }
    for (int i = 0; i < n; i++) cout << a[i] << (i + 1 < n ? " " : "\n");
    return 0;
}
