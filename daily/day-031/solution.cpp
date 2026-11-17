// Day 31: Palindrome String
// Reference solution (added automatically).

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    int i = 0, j = (int)s.size() - 1;
    while (i < j) {
        if (!isalnum((unsigned char)s[i])) { i++; continue; }
        if (!isalnum((unsigned char)s[j])) { j--; continue; }
        if (tolower((unsigned char)s[i]) != tolower((unsigned char)s[j])) {
            cout << "false" << endl;
            return 0;
        }
        i++;
        j--;
    }
    cout << "true" << endl;
    return 0;
}
