#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        return myspiralOrder(matrix);

        
    }
private:
    vector<int> myspiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty() || matrix[0].empty()) {
            return res;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        int u = 0, d = m - 1, l = 0, r = n - 1;
        while (true) {
            for (int i = l; i <= r; i++) {
                res.push_back(matrix[u][i]);
            }
            if (++u > d) {
                break;
            }
            for (int i = u; i <= d; i++) {
                res.push_back(matrix[i][r]);
            }
            if (--r < l) {
                break;
            }
            for (int i = r; i >= l; i--) {
                res.push_back(matrix[d][i]);
            }
            if (--d < u) {
                break;
            }
            for (int i = d; i >= u; i--) {
                res.push_back(matrix[i][l]);
            }
            if (++l > r) {
                break;
            }
        }
        return res;
    }
};
int main() {
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> ret = Solution().spiralOrder(matrix);
    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i] << " ";
    }
    cout << endl;
    return 0;
}