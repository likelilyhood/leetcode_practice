#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Event {
    int idx;
    int time;
};

struct Query {
    int start;
    int id;
};

int main() {
    int n, x, k;
    cin >> n >> x >> k;

    vector<Query> queries(k);

    for (int i = 0; i < k; i++) {
        cin >> queries[i].start;
        queries[i].id = i;
    }

    int m;
    cin >> m;

    vector<Event> events(m);

    for (int i = 0; i < m; i++) {
        cin >> events[i].idx >> events[i].time;
    }

    sort(events.begin(), events.end(), [](const Event& a, const Event& b) {
        return a.time < b.time;
    });

    sort(queries.begin(), queries.end(), [](const Query& a, const Query& b) {
        return a.start < b.start;
    });

    vector<int> trainCnt(n, 0);
    vector<int> ans(k, 0);

    int activeTrain = 0;
    int l = 0;
    int r = 0;

    for (int i = 0; i < k; i++) {
        int start = queries[i].start;
        int end = start + x;

        while (l < m && events[l].time < start) {
            int trainId = events[l].idx;

            trainCnt[trainId]--;

            if (trainCnt[trainId] == 0) {
                activeTrain--;
            }

            l++;
        }

        while (r < m && events[r].time < end) {
            int trainId = events[r].idx;

            if (trainCnt[trainId] == 0) {
                activeTrain++;
            }

            trainCnt[trainId]++;

            r++;
        }

        ans[queries[i].id] = activeTrain;
    }

    for (int i = 0; i < k; i++) {
        if (i > 0) {
            cout << " ";
        }
        cout << ans[i];
    }

    cout << endl;

    return 0;
}