#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> grid;
int n, m;
int startx, starty;
int destX, destY;
int k;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main() {
    cin >> n;
    cin >> m;

    grid.resize(n, vector<int>(m, 0));

    cin >> startx >> starty;
    cin >> destX >> destY;

    cin >> k;

    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        grid[x][y] = 1;
    }

    if (startx < 0 || startx >= n || starty < 0 || starty >= m ||
        destX < 0 || destX >= n || destY < 0 || destY >= m) {
        cout << -1 << endl;
        return 0;
    }

    if (grid[startx][starty] == 1 || grid[destX][destY] == 1) {
        cout << -1 << endl;
        return 0;
    }

    vector<vector<int>> dist(n, vector<int>(m, -1));
    queue<pair<int, int>> q;

    q.push({startx, starty});
    dist[startx][starty] = 0;

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        int x = cur.first;
        int y = cur.second;

        if (x == destX && y == destY) {
            cout << dist[x][y] << endl;
            return 0;
        }

        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if (newX < 0 || newX >= n || newY < 0 || newY >= m) {
                continue;
            }

            if (grid[newX][newY] == 1) {
                continue;
            }

            if (dist[newX][newY] != -1) {
                continue;
            }

            dist[newX][newY] = dist[x][y] + 1;
            q.push({newX, newY});
        }
    }

    cout << -1 << endl;

    return 0;
}