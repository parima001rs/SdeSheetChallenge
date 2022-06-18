#include<bits/stdc++.h>
using namespace std;

//TC:O(v) at worst case & SC:O(1)
int solve(int v){
    vector<int> arr = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    // arr[i] + arr[i+1] < arr[i+2] that's why greedy works here
    int coin = 0;
    for(int i=arr.size()-1; i>=0; i--){
        if(arr[i] <= v){
            coin++;
            v -= arr[i];
        }
    }
    return coin;
}

int main(){
    int v = 49;
    int coins = solve(v);
    cout<<coins;

    return 0;
}