#include <iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        return mypow(x);
    }
private:
    int mypow(int x){
        int i=x/2;//注意在这里可能会出现对应的数字类型越界，可以改用longlong 加强定义
        while (i*i>x)i/=2;
       while((i+1)*(i+1)<=x) i++;
       return i;
       
        
    }
};
int main() {
    Solution sol;
    int test_cases[] = {0, 1, 2, 4, 8, 10, 16, 25, 26, 100, 101};
    for (int x : test_cases) {
        cout << "The square root of " << x << " is " << sol.mySqrt(x) << endl;
    }
    return 0;
}