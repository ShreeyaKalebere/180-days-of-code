// Day 6: Sum of First N Numbers
// Reference solution (added automatically).

#include <iostream>
using namespace std;

int main() {
    long long n, sum = 0;
    cin >> n;
    for (long long i = 1; i <= n; i++) {
        sum += i;
    }
    cout << sum << endl;
    return 0;
}
