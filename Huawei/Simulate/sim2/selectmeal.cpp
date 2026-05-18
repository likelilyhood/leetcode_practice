#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool check(vector<int>& a, vector<int>& b, vector<int>& c) {
    unordered_set<int> used;

    for (int i = 2; i < 6; i++) {
        if (a[i] != 0) {
            if (used.count(a[i])) return false;
            used.insert(a[i]);
        }

        if (b[i] != 0) {
            if (used.count(b[i])) return false;
            used.insert(b[i]);
        }

        if (c[i] != 0) {
            if (used.count(c[i])) return false;
            used.insert(c[i]);
        }
    }

    return true;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> meal(n, vector<int>(6));

    vector<vector<int>> meat;
    vector<vector<int>> vegmeat;
    vector<vector<int>> veg;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 6; j++) {
            cin >> meal[i][j];
        }

        if (meal[i][1] == 1) {
            meat.push_back(meal[i]);
        } else if (meal[i][1] == 2) {
            vegmeat.push_back(meal[i]);
        } else if (meal[i][1] == 3) {
            veg.push_back(meal[i]);
        }
    }

    if (meat.empty() || vegmeat.empty() || veg.empty()) {
        cout << -1 << endl;
        return 0;
    }

    vector<vector<int>> ans;

    for (int i = 0; i < meat.size(); i++) {
        for (int j = 0; j < vegmeat.size(); j++) {
            for (int k = 0; k < veg.size(); k++) {
                if (check(meat[i], vegmeat[j], veg[k])) {
                    vector<int> one;
                    one.push_back(meat[i][0]);
                    one.push_back(vegmeat[j][0]);
                    one.push_back(veg[k][0]);
                    ans.push_back(one);
                }
            }
        }
    }

    if (ans.empty()) {
        cout << -1 << endl;
        return 0;
    }

    sort(ans.begin(), ans.end());

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << endl;
    }

    return 0;
}