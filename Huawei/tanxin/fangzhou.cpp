#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> dist(n);
    vector<int> speed(n);

    for (int i = 0; i < n; i++) {
        cin >> dist[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> speed[i];
    }

    vector<int> arrive(n);

    for (int i = 0; i < n; i++) {
        arrive[i] = (dist[i] - 1) / speed[i];
    }

    sort(arrive.begin(), arrive.end());

    int count = 0;

    for (int i = 0; i < n; i++) {
        if (arrive[i] < i) {
            break;
        }
        count++;
    }

    cout << count << endl;

    return 0;
}