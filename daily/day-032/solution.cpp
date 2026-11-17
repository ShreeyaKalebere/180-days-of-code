// Day 32: Reverse Words in a Sentence
// Reference solution (added automatically).

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string line, word;
    getline(cin, line);
    stringstream ss(line);
    vector<string> words;
    while (ss >> word) words.push_back(word);

    for (int i = (int)words.size() - 1; i >= 0; i--) {
        cout << words[i] << (i > 0 ? " " : "\n");
    }
    return 0;
}
