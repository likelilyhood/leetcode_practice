#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int R, C;
vector<vector<int> > grid;
vector<vector<int> > dp;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int dfs(int x, int y) {
    if (dp[x][y] != -1) {
        return dp[x][y];
    }

    dp[x][y] = 1;

    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];

        if (nx < 0 || nx >= R || ny < 0 || ny >= C) {
            continue;
        }

        if (grid[nx][ny] < grid[x][y]) {
            dp[x][y] = max(dp[x][y], dfs(nx, ny) + 1);
        }
    }

    return dp[x][y];
}

int main() {
    cin >> R >> C;

    grid.assign(R, vector<int>(C));
    dp.assign(R, vector<int>(C, -1));

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> grid[i][j];
        }
    }

    int ans = 0;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            ans = max(ans, dfs(i, j));
        }
    }

    cout << ans << endl;

    return 0;
}