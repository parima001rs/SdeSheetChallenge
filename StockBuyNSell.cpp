#include<bits/stdc++.h>
using namespace std;

//Kadane's Algo TC: O(N)
int solve(vector<int> &v){
    int buy = INT_MAX, sell = INT_MIN;
    for(int &it: v){
        buy = min(buy, it);
        sell = max(sell, it - buy);
    }
    return sell-buy;
}

int main(){
    vector<int> v = {7,1,5,3,6,4};
    cout<<solve(v);
    return 0;
}