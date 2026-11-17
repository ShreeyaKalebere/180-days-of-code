// Day 28: Transpose of a Matrix
// Reference solution (added automatically).

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int r, c;
    cin >> r >> c;
    vector<vector<int>> m(r, vector<int>(c));
    for (auto& row : m)
        for (auto& x : row) cin >> x;

    for (int j = 0; j < c; j++) {
        for (int i = 0; i < r; i++) {
            cout << m[i][j] << (i + 1 < r ? " " : "\n");
        }
    }
    return 0;
}
