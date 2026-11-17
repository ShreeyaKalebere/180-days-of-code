// Day 35: First Non-Repeating Character
// Reference solution (added automatically).

#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int freq[26] = {0};
    for (char c : s) freq[c - 'a']++;
    for (char c : s) {
        if (freq[c - 'a'] == 1) {
            cout << c << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
