#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
using namespace std;

struct Photo {
    int id;
    int time;
    int count;
};

int main() {
    int N;
    cin >> N;

    cin.ignore();

    unordered_map<int, int> idCount;
    unordered_map<int, int> idTime;

    for (int i = 0; i < N; i++) {
        string line;
        getline(cin, line);

        stringstream ss(line);

        int id, time;

        while (ss >> id >> time) {
            idCount[id]++;

            if (idTime.count(id) == 0) {
                idTime[id] = time;
            }
        }
    }

    vector<Photo> ans;

    for (unordered_map<int, int>::iterator it = idCount.begin(); it != idCount.end(); ++it) {
        int id = it->first;
        int cnt = it->second;

        if (cnt > 1) {
            Photo p;
            p.id = id;
            p.time = idTime[id];
            p.count = cnt;

            ans.push_back(p);
        }
    }

    sort(ans.begin(), ans.end(), [](const Photo& a, const Photo& b) {
        if (a.time != b.time) {
            return a.time < b.time;
        }
        return a.id < b.id;
    });

    for (int i = 0; i < ans.size(); i++) {
        if (i > 0) {
            cout << " ";
        }

        cout << ans[i].id << " " << ans[i].count;
    }

    cout << endl;

    return 0;
}