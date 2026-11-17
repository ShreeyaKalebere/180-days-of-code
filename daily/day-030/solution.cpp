// Day 30: Spiral Order of a Matrix
// Reference solution (added automatically).

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int r, c;
    cin >> r >> c;
    vector<vector<int>> m(r, vector<int>(c));
    for (auto& row : m) for (auto& x : row) cin >> x;

    vector<int> out;
    int top = 0, bottom = r - 1, left = 0, right = c - 1;
    while (top <= bottom && left <= right) {
        for (int j = left; j <= right; j++) out.push_back(m[top][j]);
        top++;
        for (int i = top; i <= bottom; i++) out.push_back(m[i][right]);
        right--;
        if (top <= bottom) {
            for (int j = right; j >= left; j--) out.push_back(m[bottom][j]);
            bottom--;
        }
        if (left <= right) {
            for (int i = bottom; i >= top; i--) out.push_back(m[i][left]);
            left++;
        }
    }
    for (size_t i = 0; i < out.size(); i++) cout << out[i] << (i + 1 < out.size() ? " " : "\n");
    return 0;
}
