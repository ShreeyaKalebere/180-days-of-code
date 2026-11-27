// Day 48: Two Sum in a Sorted Array
// Reference solution (added automatically).

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    long long target;
    cin >> n >> target;
    vector<long long> a(n);
    for (auto& x : a) cin >> x;

    int i = 0, j = n - 1;
    while (i < j) {
        long long s = a[i] + a[j];
        if (s == target) {
            cout << i << " " << j << endl;
            return 0;
        }
        if (s < target) i++;
        else j--;
    }
    cout << "-1 -1" << endl;
    return 0;
}
