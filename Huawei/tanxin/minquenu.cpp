#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> number;
    int x;

    while (cin >> x) {
        number.push_back(x);
    }

    int len = number.size();

    if (len == 0 || len % 2 == 1) {
        cout << "null" << endl;
        return 0;
    }

    int half = len / 2;

    sort(number.begin(), number.end());

    vector<int> n1, n2;
    vector<int> single;

    for (int i = 0; i < len; i++) {
        if (i + 2 < len && number[i] == number[i + 1] && number[i + 1] == number[i + 2]) {
            cout << "null" << endl;
            return 0;
        }

        if (i + 1 < len && number[i] == number[i + 1]) {
            n1.push_back(number[i]);
            n2.push_back(number[i + 1]);
            i++;
        } else {
            single.push_back(number[i]);
        }
    }

    if (n1.size() > half || n2.size() > half) {
        cout << "null" << endl;
        return 0;
    }

    for (int i = 0; i < single.size(); i++) {
        if (n1.size() < half) {
            n1.push_back(single[i]);
        } else {
            n2.push_back(single[i]);
        }
    }

    if (n1.size() != half || n2.size() != half) {
        cout << "null" << endl;
        return 0;
    }

    sort(n1.begin(), n1.end());
    sort(n2.begin(), n2.end());

    for (int i = 0; i < half; i++) {
        if (i > 0) cout << " ";
        cout << n1[i];
    }
    cout << endl;

    for (int i = 0; i < half; i++) {
        if (i > 0) cout << " ";
        cout << n2[i];
    }
    cout << endl;

    return 0;
}