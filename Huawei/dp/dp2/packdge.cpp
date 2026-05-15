#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, target;
    vector<int> awards;

    cin >> n;
    vector<int> cnt(101, 0);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }

    cin >> target;

    vector<int> dp(target + 1, 0);
    dp[0] = 1;

    for (int v = 1; v <= 100; v++) {
        if (cnt[v] == 0) continue;

        vector<int> newDp = dp;

        for (int j = 0; j <= target; j++) {
            if (dp[j] == 0) continue;

            for (int k = 1; k <= cnt[v]; k++) {
                int sum = j + k * v;
                if (sum > target) break;

                newDp[sum] += dp[j];
            }
        }

        dp = newDp;
    }

    cout << dp[target] << endl;
    return 0;
}