#include<iostream>
using namespace std;



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        int dis1 = 100;
        int dis2 = n*0.10;
        cout<< max(dis1, dis2)<<endl;                                    
    }
    return 0;
}