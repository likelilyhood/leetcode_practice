#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int abilty;
int m, n;
vector<vector<int> > gird;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int startx, starty;
int endx, endy;

int main() {
    cin >> abilty;
    cin >> m >> n;

    gird.resize(m, vector<int>(n));

    int height = -1;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> gird[i][j];

            if (gird[i][j] == 0) {
                startx = i;
                starty = j;
            }

            if (gird[i][j] > height) {
                height = gird[i][j];
                endx = i;
                endy = j;
            }
        }
    }

    vector<vector<int> > dist(m, vector<int>(n, -1));

    queue<pair<int, int> > q;
    q.push({startx, starty});
    dist[startx][starty] = 0;

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        int x = cur.first;
        int y = cur.second;

        if (x == endx && y == endy) {
            cout << dist[x][y] << endl;
            return 0;
        }

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
                continue;
            }

            if (dist[nx][ny] != -1) {
                continue;
            }

            if (gird[nx][ny] > gird[x][y] + abilty) {
                continue;
            }

            if (gird[nx][ny] < gird[x][y] - abilty) {
                continue;
            }

            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }

    cout << -1 << endl;
    return 0;
}