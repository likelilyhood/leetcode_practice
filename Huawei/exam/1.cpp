#include <algorithm>
#include <array>
#include <cmath>
#include <cstdint>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;
struct Edge {
    double u,v;
    int  y=1;
    
};
double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}
int main() {
    int n,e;
    double alpha;
    cin >> n >> e >> alpha;
    vector<Edge> edges(n);
    for (int i = 0; i < n; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].y;
        
    }
    Edge test_edges;
    cin >> test_edges.u >> test_edges.v ;
    
    double w1 = 0.0;
    double w2 = 0.0;
    double b= 0.0;
    for(int i=0;i<e;i++){        
        double dw1=0.0;
        double dw2 =0.0;
        double db=0.0;  
        double y_pred;
        for(int j=0;j<n;j++){
            double z= w1*edges[j].u + w2*edges[j].v + b;
            y_pred = sigmoid(z);
            double error = 0.0;
            error = y_pred - edges[j].y;
            dw1+= error * edges[j].u;
            dw2+= error * edges[j].v;
            db+= error;
        edges[j].y= y_pred;
        }
        dw1/=n;
        dw2/=n;
        db/=n;  
        w1-= alpha*dw1;
        w2-= alpha*dw2;
        b-= alpha*db;
        //cout<<"Epoch: "<<i+1<<" w1: "<<w1<<" w2: "<<w2<<" b: "<<b<<endl;
    }
    double z= w1*test_edges.u + w2*test_edges.v + b;
    //cout<<"z: "<<z<<endl;
    double y = sigmoid(z);
    
    cout << fixed << setprecision(4) << y << endl;
    return 0;
}
