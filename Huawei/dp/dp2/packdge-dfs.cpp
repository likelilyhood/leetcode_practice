#include <iostream>
#include <vector>
using namespace std;

int target;
int ans = 0;
vector<int> vals;
vector<int> cnt;

void dfs(int idx, int sum) {
    if (sum > target) {
        return;
    }

    if (idx == vals.size()) {
        if (sum == target) {
            ans++;
        }
        return;
    }

    int v = vals[idx];

    for (int k = 0; k <= cnt[idx]; k++) {
        dfs(idx + 1, sum + k * v);
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> countValue(101, 0);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        countValue[x]++;
    }

    cin >> target;

    for (int v = 1; v <= 100; v++) {
        if (countValue[v] > 0) {
            vals.push_back(v);
            cnt.push_back(countValue[v]);
        }
    }

    dfs(0, 0);

    cout << ans << endl;
    return 0;
}