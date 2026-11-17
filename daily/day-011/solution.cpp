// Day 11: Count Vowels in a String
// Reference solution (added automatically).

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    int count = 0;
    for (char ch : s) {
        char c = tolower(static_cast<unsigned char>(ch));
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') count++;
    }
    cout << count << endl;
    return 0;
}
