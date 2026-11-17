// Day 8: Maximum of Three Using a Function
// Reference solution (added automatically).

#include <iostream>
using namespace std;

int maxOfThree(int a, int b, int c) {
    int best = a;
    if (b > best) best = b;
    if (c > best) best = c;
    return best;
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << maxOfThree(a, b, c) << endl;
    return 0;
}
