#include <iostream>
using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        return mysqrt(num);
    }

private:
    bool mysqrt(int x) {
        if (x < 0) return false;
        if (x == 0) return true;

        long long i = x / 2;
        while (i * i > x) {
            i /= 2;
        }

        while (i * i < x) {
            i++;
        }

        return i * i == x;
    }
};

int main() {
    Solution solution;
    int test_cases[] = {0, 1, 16, 14, 25, 26, -1};
    for (int num : test_cases) {
        if (solution.isPerfectSquare(num)) {
            cout << num << " is a perfect square." << endl;
        } else {
            cout << num << " is not a perfect square." << endl;
        }
    }
    return 0;
}