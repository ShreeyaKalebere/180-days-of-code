// Day 24: Reverse an Array In Place
// Reference solution (added automatically).

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;

    int i = 0, j = n - 1;
    while (i < j) {
        swap(a[i], a[j]);
        i++;
        j--;
    }
    for (int k = 0; k < n; k++) cout << a[k] << (k + 1 < n ? " " : "\n");
    return 0;
}
