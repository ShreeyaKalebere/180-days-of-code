// Day 18: Sieve of Eratosthenes
// Reference solution (added automatically).

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = false;
    if (n >= 1) isPrime[1] = false;
    for (int i = 2; (long long)i * i <= n; i++) {
        if (!isPrime[i]) continue;
        for (int j = i * i; j <= n; j += i) isPrime[j] = false;
    }
    bool first = true;
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            if (!first) cout << " ";
            cout << i;
            first = false;
        }
    }
    cout << endl;
    return 0;
}
