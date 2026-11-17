// Day 12: Reverse an Array Using Pointers
// Reference solution (added automatically).

#include <iostream>
#include <vector>
using namespace std;

void swapValues(int& x, int& y) {
    int t = x;
    x = y;
    y = t;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int* left = a.data();
    int* right = a.data() + n - 1;
    while (left < right) {
        swapValues(*left, *right);
        left++;
        right--;
    }

    for (int i = 0; i < n; i++) cout << a[i] << (i + 1 < n ? " " : "\n");
    return 0;
}
