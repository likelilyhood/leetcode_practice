#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int findMinIndex(vector<long long>& number, int l, int r) {
    int pos = l;

    for (int i = l; i <= r; i++) {
        if (number[i] < number[pos]) {
            pos = i;
        }
    }

    return pos;
}

int main() {
    int n;
    cin >> n;

    vector<long long> number(n);

    for (int i = 0; i < n; i++) {
        cin >> number[i];
    }

    int cnt = 0;
    int start = 0;

    while (start < n) {
        int pos = findMinIndex(number, start, n - 1);

        long long cur = number[pos] * 2;

        for (int j = start; j < pos; j++) {
            if (number[j] > cur) {
                cnt++;
            }
        }

        start = pos + 1;
    }

    cout << cnt << endl;

    return 0;
}