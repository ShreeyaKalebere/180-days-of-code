// Day 41: Selection Sort
// Reference solution (added automatically).

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;

    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minIdx]) minIdx = j;
        }
        swap(a[i], a[minIdx]);
    }
    for (int i = 0; i < n; i++) cout << a[i] << (i + 1 < n ? " " : "\n");
    return 0;
}
