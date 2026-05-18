#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    string target;
    cin >> target;

    map<string, int> mp;

    string s;
    while (cin >> s) {
        if (s.size() <= target.size() && target.substr(0, s.size()) == s) {
            mp[s]++;
        }
    }

    if (mp.empty()) {
        cout << "null" << endl;
        return 0;
    }

    vector<pair<string, int> > ans;

    for (map<string, int>::iterator it = mp.begin(); it != mp.end(); ++it) {
        ans.push_back(*it);
    }

    sort(ans.begin(), ans.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
        return a.first.size() > b.first.size();
    });

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i].first << " " << ans[i].second << endl;
    }

    return 0;
}