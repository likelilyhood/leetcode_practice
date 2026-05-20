#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n;
vector<long long> treeArr;

int findLCA(int index, long long a, long long b) {
    if (index >= n) {
        return -1;
    }

    if (treeArr[index] == -1) {
        return -1;
    }

    if (treeArr[index] == a || treeArr[index] == b) {
        return index;
    }

    int left = findLCA(index * 2 + 1, a, b);
    int right = findLCA(index * 2 + 2, a, b);

    if (left != -1 && right != -1) {
        return index;
    }

    if (left != -1) {
        return left;
    }

    return right;
}

int countSubtree(int index) {
    if (index >= n) {
        return 0;
    }

    if (treeArr[index] == -1) {
        return 0;
    }

    int leftCount = countSubtree(index * 2 + 1);
    int rightCount = countSubtree(index * 2 + 2);

    return 1 + leftCount + rightCount;
}

int main() {
    cin >> n;

    treeArr.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> treeArr[i];
    }

    long long target1, target2;
    cin >> target1 >> target2;

    int cofatherIndex = findLCA(0, target1, target2);

    int total = countSubtree(cofatherIndex);

    cout << total - 1 << endl;

    return 0;
}