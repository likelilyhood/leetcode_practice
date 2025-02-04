#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        return mycompare(s, t);
    }

private:
    bool mycompare(string s, string t) {
        // 处理字符串 s
        string processedS = processString(s);
        // 处理字符串 t
        string processedT = processString(t);
        // 比较处理后的字符串
        return processedS == processedT;
    }

    string processString(string str) {
        string result;
        for (char ch : str) {
            if (ch != '#') {
                result.push_back(ch);
            } else if (!result.empty()) {
                result.pop_back();
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    string s = "ab#c";
    string t = "ad#c";
    bool result = sol.backspaceCompare(s, t);
    cout << "字符串 " << s << " 和 " << t << " 是否相等: " << (result ? "是" : "否") << endl;
    return 0;
}