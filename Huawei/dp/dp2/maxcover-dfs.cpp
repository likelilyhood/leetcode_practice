#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int areaReq, budget, n;
vector<int> coverage, cost;

int ansCost = INT_MAX;
int ansCoverage = 0;

void dfs(int idx, int totalCost, int totalCoverage) {
    if (totalCost > budget) {
        return;
    }

    if (idx == n) {
        if (totalCoverage >= areaReq) {
            if (totalCost < ansCost) {
                ansCost = totalCost;
                ansCoverage = totalCoverage;
            } else if (totalCost == ansCost && totalCoverage > ansCoverage) {
                ansCoverage = totalCoverage;
            }
        }
        return;
    }

    // 不选第 idx 个接入点
    dfs(idx + 1, totalCost, totalCoverage);

    // 选第 idx 个接入点
    dfs(idx + 1, totalCost + cost[idx], totalCoverage + coverage[idx]);
}

int main() {
    cin >> areaReq >> budget >> n;

    coverage.resize(n);
    cost.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> coverage[i] >> cost[i];
    }

    dfs(0, 0, 0);

    if (ansCost == INT_MAX) {
        cout << 0 << " " << 0 << endl;
    } else {
        cout << ansCost << " " << ansCoverage << endl;
    }

    return 0;
}