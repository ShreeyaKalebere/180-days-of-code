// Day 23: Second Largest Element
// Reference solution (added automatically).

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (auto& x : a) cin >> x;

    long long first = LLONG_MIN, second = LLONG_MIN;
    for (long long x : a) {
        if (x > first) {
            second = first;
            first = x;
        } else if (x < first && x > second) {
            second = x;
        }
    }
    cout << (second == LLONG_MIN ? -1 : second) << endl;
    return 0;
}
