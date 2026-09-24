#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<string>
using namespace std;

int num;
int gradstime[1000];
string s;
double lr,dr;
char c;


int main(){
    int len=0;
   while(1){
    scanf("%d",&gradstime[len]);
    len++;
    char temp;
    scanf("%c",&temp);
    if(temp==';'){
        break;
    }
   }
   scanf("%d",&num);
   getchar();
   cin>>lr;
   getchar();
   cin>>dr;
   int sum=0;
   for(int i=0;i<len;i++){
       sum+=gradstime[i];
   }
   double bestdiv=sum*1.0/num;
   int bestint=bestdiv;
   if(bestdiv-bestint>0)bestint++;
   sort(gradstime,gradstime+len);
   void dfs(int index,int count,int sum,int bestint,int len);
   dfs(0,0,0,bestint,len);
   int sum_gardetime[1000];
   vector<int> dp(0,0);
   for(int i=0;i<num;i++){
       dp.push_back(0);
   } 
   for(int i=0;i<num;i++){
       sum_gardetime[i]=0;
   }
   for(int i=len-1;i>=0;i--){
       int minindex=0;
       for(int j=1;j<num;j++){
           if(dp[j]<dp[minindex]){
               minindex=j;
           }
       }
       dp[minindex]+=gradstime[i];
       sum_gardetime[minindex]+=gradstime[i];
   }
  
   double totalcost=0;
   for(int j=0;j<num;j++){

        double tempdr=pow(dr,bestint*1.0-sum_gardetime[j]);

       double lr_i=lr*tempdr;
     
       totalcost+=lr_i*sum_gardetime[j];
      
   }
   
   cout<<bestint<<";";
   printf("%.4f",totalcost);
   cout<<endl;
    return 0;
}
void dfs(int index,int count,int sum,int bestint,int len){
       if(count==num){
           if(sum<bestint){
               bestint=sum;
           }
           return;
       }
       for(int i=index;i<len;i++){
           dfs(i+1,count+1,sum+gradstime[i],bestint,len);
       }
   }