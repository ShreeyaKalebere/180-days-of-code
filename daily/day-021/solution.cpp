// Day 21: Reverse a Number and Palindrome Check
// Reference solution (added automatically).

#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;
    long long original = n, rev = 0;
    while (n > 0) {
        rev = rev * 10 + n % 10;
        n /= 10;
    }
    cout << rev << "\n";
    cout << (rev == original ? "Palindrome" : "Not Palindrome") << "\n";
    return 0;
}
