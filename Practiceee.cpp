#include<iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    int count, ans;
    while(t--){
        int a, b;
        cin>>a>>b;
        count = 0;
        while(1){
            if(a%3==0||b%3==0){
                cout<<count<<endl;
                break;
            }
            ans=abs(a-b);
            if(a>b){   
                a=abs(a-b);
                count++;
            }
            else{
                b=abs(a-b);
                count++;
            }                                 
        }
    }
    cout<<count;
    return 0;
}