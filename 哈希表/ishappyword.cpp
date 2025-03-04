#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;    
class Solution{
    public:
    bool isHappy(int n){
    unordered_set<int> s;
    while(n!=1){
        if(s.find(n)!=s.end()){
            return false;
        }
        s.insert(n);
        n=getSum(n);

    }
    return true;
    
}
    private:
    int getSum(int n){
        int sum=0;
        while(n>0){
            sum+=(n%10)*(n%10);
            n/=10;
        }
        return sum;
    }
};
int main(){
    Solution s;
    int n;
   n=19;
    cout<<s.isHappy(n)<<endl;
    return 0;
}