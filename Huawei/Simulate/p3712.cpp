#include <iostream>
using namespace std;

int main() {
    long long n, m, h;
    cin >> n >> m >> h;

    long long rowSum;

    if (h <= m) {
        rowSum = h * (h + 1) / 2;
    } else {
        rowSum = m * (m + 1) / 2 + m * (h - m);
    }

    long long ans = n * rowSum;

    cout << ans << endl;

    return 0;
}