#include<string>
#include<iostream>
using namespace std;
int main(){
    string s1,s2;
    cin>>s1>>s2;
    int m=s1.size(),n=s2.size();
    
    int maxlen=0;
    for(int i=0;i<m;i++){
        int lest=0;
        for(int j=0;j<n;j++){
            if(s1[i]==s2[j]){
                lest++;
                int k=i+1,l=j+1;
                while(k<m&&l<n&&s1[k]==s2[l]){
                    lest++;
                    k++;
                    l++;
                }
               
            }
            maxlen=max(maxlen,lest);
             lest=0;
        }   
     }
    cout<<maxlen<<endl;
    return 0;
}