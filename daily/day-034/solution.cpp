// Day 34: Valid Anagram
// Reference solution (added automatically).

#include <iostream>
#include <string>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    if (a.size() != b.size()) {
        cout << "false" << endl;
        return 0;
    }
    int count[26] = {0};
    for (size_t i = 0; i < a.size(); i++) {
        count[a[i] - 'a']++;
        count[b[i] - 'a']--;
    }
    for (int i = 0; i < 26; i++) {
        if (count[i] != 0) {
            cout << "false" << endl;
            return 0;
        }
    }
    cout << "true" << endl;
    return 0;
}
