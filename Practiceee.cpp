#include<iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    int count, ans;
    while(t--){
        int a, b;
        cin>>a>>b;
        
        while(a < b){
            if(a % 2 == 0)
                a += 2;
            else
                a += 1;
        }

        if(a == b)
            cout<<"yes";
        else
            cout<<"no";
        cout<<endl;
    }
    
    return 0;
}