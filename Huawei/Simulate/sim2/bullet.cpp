#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> boards(n);
    for (int i = 0; i < n; i++) {
        cin >> boards[i];
    }

    int x;
    cin >> x;

    int pos = 0;

    for (int i = 0; i < n; i++) {
        int a = boards[i];
        int b = boards[(i + 1) % n];

        if (a <= b) {
            if (a <= x && x <= b) {
                pos = i + 1;
                break;
            }
        } else {
            if (x >= a || x <= b) {
                pos = i + 1;
                break;
            }
        }
    }

    for (int i = 0; i <= n; i++) {
        if (i == pos) {
            cout << x;
        } else {
            int idx;
            if (i < pos) {
                idx = i;
            } else {
                idx = i - 1;
            }
            cout << boards[idx];
        }

        if (i != n) {
            cout << " ";
        }
    }

    cout << endl;
    return 0;
}