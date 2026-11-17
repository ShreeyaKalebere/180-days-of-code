// Day 33: Character Frequency
// Reference solution (added automatically).

#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int freq[26] = {0};
    for (char c : s) freq[c - 'a']++;
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) cout << char('a' + i) << " " << freq[i] << "\n";
    }
    return 0;
}
