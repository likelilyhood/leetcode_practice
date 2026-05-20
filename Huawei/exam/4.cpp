#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct Skill {
    int id;
    int time;
    int power;
    int flag;
    int preId;
};

const int NEG = -1000000000;

int N, T;
vector<Skill> skills;
vector<vector<int> > children;
vector<vector<int> > dp;

void dfs(int u) {
    for (int i = 0; i <= T; i++) {
        dp[u][i] = NEG;
    }

    if (u == 0) {
        dp[u][0] = 0;
    } else {
        int cost = skills[u].time;
        int val = skills[u].power;

        if (cost <= T) {
            dp[u][cost] = val;
        }
    }

    for (int i = 0; i < children[u].size(); i++) {
        int v = children[u][i];

        dfs(v);

        vector<int> temp(T + 1, NEG);

        for (int used = 0; used <= T; used++) {
            if (dp[u][used] == NEG) {
                continue;
            }

            // 不选子技能 v
            temp[used] = max(temp[used], dp[u][used]);

            // 选子技能 v 的某种时间方案
            for (int add = 0; used + add <= T; add++) {
                if (dp[v][add] == NEG) {
                    continue;
                }

                temp[used + add] = max(temp[used + add], dp[u][used] + dp[v][add]);
            }
        }

        dp[u] = temp;
    }
}

int main() {
    cin >> N >> T;

    skills.resize(N + 1);
    children.resize(N + 1);
    dp.resize(N + 1, vector<int>(T + 1, NEG));

    map<int, int> idToIndex;

    for (int i = 1; i <= N; i++) {
        cin >> skills[i].id >> skills[i].time >> skills[i].power >> skills[i].flag;

        if (skills[i].flag == 1) {
            cin >> skills[i].preId;
        } else {
            skills[i].preId = -1;
        }

        idToIndex[skills[i].id] = i;
    }

    for (int i = 1; i <= N; i++) {
        if (skills[i].flag == 0) {
            children[0].push_back(i);
        } else {
            int preIndex = idToIndex[skills[i].preId];
            children[preIndex].push_back(i);
        }
    }

    dfs(0);

    int ans = 0;

    for (int t = 0; t <= T; t++) {
        ans = max(ans, dp[0][t]);
    }

    cout << ans << endl;

    return 0;
}