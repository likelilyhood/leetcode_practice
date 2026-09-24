
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
vector<int> f;

// 判断最大负载限制 X 是否可行
bool check(int X) {
    int stageCount = 1;
    int current = 0;

    for (int i = 0; i < N; i++) {

        if (current + f[i] <= X) {
            // TODO 1
            current += f[i];
        }
        else {
            // TODO 2
            stageCount++;
            current = f[i];
        }

    }

    // TODO 3
    return stageCount <= K;
}

int main() {
    cin >> N >> K;

    f.resize(N);

    int left = 0;
    int right = 0;

    for (int i = 0; i < N; i++) {
        cin >> f[i];

        // TODO 4: 更新二分左边界
        left = max(left, f[i]);
        // TODO 5: 更新二分右边界
        right += f[i];

    }

    while (left < right) {

        int mid = left + (right - left) / 2;

        if (check(mid)) {
            // TODO 6
            right = mid;
        }
        else {
            // TODO 7
            left = mid + 1;
        }

    }

    cout << left << endl;

    return 0;
}