#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <queue>
#include <algorithm>
#include <limits>
using namespace std;

int main() {
    int N;
    cin >> N;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<string> > lines(N);
    map<string, vector<int> > stationToLines;

    for (int i = 0; i < N; i++) {
        string line;
        getline(cin, line);

        stringstream ss(line);
        string station;

        while (ss >> station) {
            lines[i].push_back(station);
            stationToLines[station].push_back(i);
        }
    }

    string startStation, endStation;
    cin >> startStation >> endStation;

    if (stationToLines.count(startStation) == 0 || stationToLines.count(endStation) == 0) {
        cout << "NA" << endl;
        return 0;
    }

    vector<vector<pair<int, string> > > graph(N);

    for (map<string, vector<int> >::iterator it = stationToLines.begin(); it != stationToLines.end(); ++it) {
        string station = it->first;
        vector<int> vec = it->second;

        for (int i = 0; i < vec.size(); i++) {
            for (int j = i + 1; j < vec.size(); j++) {
                int a = vec[i];
                int b = vec[j];

                graph[a].push_back(make_pair(b, station));
                graph[b].push_back(make_pair(a, station));
            }
        }
    }

    queue<int> q;

    vector<int> dist(N, -1);
    vector<int> preLine(N, -1);
    vector<string> preStation(N);

    vector<int> isEndLine(N, 0);

    for (int i = 0; i < stationToLines[endStation].size(); i++) {
        int line = stationToLines[endStation][i];
        isEndLine[line] = 1;
    }

    for (int i = 0; i < stationToLines[startStation].size(); i++) {
        int line = stationToLines[startStation][i];
        q.push(line);
        dist[line] = 0;
    }

    int endLine = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (isEndLine[u]) {
            endLine = u;
            break;
        }

        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i].first;
            string transferStation = graph[u][i].second;

            if (dist[v] != -1) {
                continue;
            }

            dist[v] = dist[u] + 1;
            preLine[v] = u;
            preStation[v] = transferStation;
            q.push(v);
        }
    }

    if (endLine == -1) {
        cout << "NA" << endl;
        return 0;
    }

    vector<string> transfers;

    int cur = endLine;

    while (preLine[cur] != -1) {
        transfers.push_back(preStation[cur]);
        cur = preLine[cur];
    }

    reverse(transfers.begin(), transfers.end());

    cout << startStation;

    for (int i = 0; i < transfers.size(); i++) {
        cout << "-" << transfers[i];
    }

    cout << "-" << endStation << endl;

    cout << dist[endLine] + 2 << endl;

    return 0;
}