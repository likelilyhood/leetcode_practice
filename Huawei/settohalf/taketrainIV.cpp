#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check(vector<int>& people, int M, long long limit) {
    int used = 1;
    long long cur = 0;

    for (int i = 0; i < people.size(); i++) {
        if (cur + people[i] <= limit) {
            cur += people[i];
        } else {
            used++;
            cur = people[i];
        }
    }

    return used <= M;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> people(N);

    long long left = 0;
    long long right = 0;

    for (int i = 0; i < N; i++) {
        cin >> people[i];
        left = max(left, (long long)people[i]);
        right += people[i];
    }

    while (left < right) {
        long long mid = (left + right) / 2;

        if (check(people, M, mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    cout << left << endl;

    return 0;
}