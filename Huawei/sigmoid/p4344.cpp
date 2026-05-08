#include<iostream>
#include<vector>
#include<cmath>
#include<iomanip>
using namespace std;
double sigmoid(double z){
    if(z >= 0){
        return 1.0 / (1.0 + exp(-z));
    }else{
        double ez = exp(z);
        return ez / (1.0 + ez);
    }
}
struct customer
{
    double  old;
    double income;
    double time;
    int buy=0;
};

int main(){
    int n,maxt,m;
    double alpha,lamada,tol;
    cin>>n>>maxt>>alpha>>lamada>>tol;
    vector<customer> customers(n);
    for(int i=0;i<n;i++){
        cin>>customers[i].old>>customers[i].income>>customers[i].time>>customers[i].buy;
    }
    cin>>m;
    vector<customer> test(m);
    for(int i=0;i<m;i++){
        cin>>test[i].old>>test[i].income>>test[i].time;
    }
    double w0 = 0.0;
double w1 = 0.0;
double w2 = 0.0;
double b = 0.0;

double lastLoss = 1e18;

while(maxt--){
    double dw0 = 0.0;
    double dw1 = 0.0;
    double dw2 = 0.0;
    double db = 0.0;
    double loss = 0.0;

    for(int i = 0; i < n; i++){
        double z = w0 * customers[i].old
                 + w1 * customers[i].income
                 + w2 * customers[i].time
                 + b;

        double pred = sigmoid(z);

        double eps = 1e-15;
        if(pred < eps){
            pred = eps;
        }
        if(pred > 1.0 - eps){
            pred = 1.0 - eps;
        }

        loss += -(customers[i].buy * log(pred)
               + (1 - customers[i].buy) * log(1.0 - pred));

        double diff = pred - customers[i].buy;

        dw0 += diff * customers[i].old;
        dw1 += diff * customers[i].income;
        dw2 += diff * customers[i].time;
        db += diff;
    }

    double l2 = w0 * w0 + w1 * w1 + w2 * w2;

    loss = loss / n + lamada * l2 / (2.0 * n);
    if(fabs(lastLoss - loss) < tol){
            break;
        }
    lastLoss = loss;
    dw0 = dw0 / n + lamada * w0 / n;
    dw1 = dw1 / n + lamada * w1 / n;
    dw2 = dw2 / n + lamada   * w2 / n;
    db = db / n;

    w0 -= alpha * dw0;
    w1 -= alpha * dw1;
    w2 -= alpha * dw2;
    b -= alpha * db;

    

    
}
    for(int i=0;i<m;i++){
        double z=w0*test[i].old+w1*test[i].income+w2*test[i].time+b;
        double y_pred=sigmoid(z);
        if(y_pred>=0.5){
            cout<<"1 ";
            printf("%.4f ",y_pred);
            cout<<endl;
        }else{
            cout<<"0 ";

            printf("%.4f ",y_pred);
            cout<<endl;
        }
    }
    cout<<endl;
    return 0;
}