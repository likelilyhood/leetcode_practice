#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Edge {
    int to;
    int time;
    int cost;
};

struct State {
    int time;
    int node;
    int energy;
};

// priority_queue 默认大根堆，所以这里反过来写，变成小根堆
struct Cmp {
    bool operator()(const State& a, const State& b) const {
        return a.time > b.time;
    }
};

int main() {
    int N, K, M, S, T, E, maxE;
    cin >> N >> K >> M >> S >> T >> E >> maxE;

    vector<vector<Edge> > graph(N);

    for (int i = 0; i < M; i++) {
        int from, to, time, cost;
        cin >> from >> to >> time >> cost;

        Edge e;
        e.to = to;
        e.time = time;
        e.cost = cost;

        graph[from].push_back(e);
    }

    vector<int> isCharge(N, 0);

    for (int i = 0; i < K; i++) {
        int cp;
        cin >> cp;
        isCharge[cp] = 1;
    }

    const int INF = 1000000000;

    vector<vector<int> > dist(N, vector<int>(maxE + 1, INF));

    priority_queue<State, vector<State>, Cmp> pq;

    dist[S][E] = 0;

    State start;
    start.time = 0;
    start.node = S;
    start.energy = E;
    pq.push(start);

    while (!pq.empty()) {
        State cur = pq.top();
        pq.pop();

        int curTime = cur.time;
        int u = cur.node;
        int energy = cur.energy;

        if (curTime != dist[u][energy]) {
            continue;
        }

        if (u == T) {
            cout << curTime << endl;
            return 0;
        }

        // 选择在充电站充电
        if (isCharge[u] == 1 && energy < maxE) {
            if (dist[u][maxE] > curTime + 1) {
                dist[u][maxE] = curTime + 1;

                State next;
                next.time = curTime + 1;
                next.node = u;
                next.energy = maxE;
                pq.push(next);
            }
        }

        // 选择沿道路行驶
        for (int i = 0; i < graph[u].size(); i++) {
            Edge e = graph[u][i];

            if (energy < e.cost) {
                continue;
            }

            int v = e.to;
            int newEnergy = energy - e.cost;
            int newTime = curTime + e.time;

            if (dist[v][newEnergy] > newTime) {
                dist[v][newEnergy] = newTime;

                State next;
                next.time = newTime;
                next.node = v;
                next.energy = newEnergy;
                pq.push(next);
            }
        }
    }

    cout << -1 << endl;

    return 0;
}