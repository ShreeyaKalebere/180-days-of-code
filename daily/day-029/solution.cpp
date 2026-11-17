// Day 29: Matrix Multiplication
// Reference solution (added automatically).

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m, p;
    cin >> n >> m >> p;
    vector<vector<long long>> A(n, vector<long long>(m)), B(m, vector<long long>(p));
    for (auto& row : A) for (auto& x : row) cin >> x;
    for (auto& row : B) for (auto& x : row) cin >> x;

    vector<vector<long long>> C(n, vector<long long>(p, 0));
    for (int i = 0; i < n; i++)
        for (int k = 0; k < m; k++)
            for (int j = 0; j < p; j++)
                C[i][j] += A[i][k] * B[k][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < p; j++)
            cout << C[i][j] << (j + 1 < p ? " " : "\n");
    return 0;
}
