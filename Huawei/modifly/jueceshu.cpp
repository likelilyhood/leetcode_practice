#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int type;

    // 内部节点使用
    int idx = 0;
    int val = 0;
    int left = 0;
    int right = 0;

    // 叶子节点使用
    int label = 0;
};

int predict(const vector<Node>& tree, const vector<int>& x) {
    int cur = 1;  // 根节点编号固定为1

    while (tree[cur].type == 1) {
        int idx = tree[cur].idx;
        int val = tree[cur].val;

        if (x[idx] <= val) {
            cur = tree[cur].left;
        } else {
            cur = tree[cur].right;
        }
    }

    // 到达叶子节点
    return tree[cur].label;
}

int main() {

    int T, M, N;
    cin >> T >> M >> N;

    vector<vector<Node>> forest(T);

    // 读取T棵决策树
    for (int t = 0; t < T; ++t) {
        int K;
        cin >> K;

        // 节点编号为1~K
        forest[t].resize(K + 1);

        for (int i = 1; i <= K; ++i) {
            int type;
            cin >> type;

            forest[t][i].type = type;

            if (type == 1) {
                cin >> forest[t][i].idx
                    >> forest[t][i].val
                    >> forest[t][i].left
                    >> forest[t][i].right;
            } else {
                cin >> forest[t][i].label;
            }
        }
    }

    // 依次预测N笔交易
    for (int i = 0; i < N; ++i) {
        // 特征编号也从1开始
        vector<int> x(M + 1);

        for (int j = 1; j <= M; ++j) {
            cin >> x[j];
        }

        int cnt1 = 0;

        for (int t = 0; t < T; ++t) {
            cnt1 += predict(forest[t], x);
        }

        // 只有1的票数严格超过一半才输出1
        // 平票自动输出0
        if (cnt1 > T / 2) {
            cout << 1 << '\n';
        } else {
            cout << 0 << '\n';
        }
    }

    return 0;
}