#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        return myminWindow(s, t);
    }
private:
    string myminWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        if (n == 0 || m == 0) {
            return "";
        }
        vector<int> hash(128, 0);
        for (char ch : t) {
            hash[ch]++;
        }
        int start = 0, end = 0;
        int minLen = INT_MAX;
        int minStart = 0;
        int counter = m;
        while (end < n) {
            if (hash[s[end]] > 0) {
                counter--;
            }
            hash[s[end]]--;
            end++;
            while (counter == 0) {
                if (end - start < minLen) {
                    minLen = end - start;
                    minStart = start;
                }
                if (hash[s[start]] == 0) {
                    counter++;
                }
                hash[s[start]]++;
                start++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};

int main() {
    string s = "ADOBECODEBANC";
    string t = "ABCD";
    string ret = Solution().minWindow(s, t);
    cout << ret << endl;
    return 0;
}