#include<bits/stdc++.h>
using namespace std;

//TC:O(N) & SC:O(1)
int solve(vector<int>&v){
    int count = 0, res = 0;
    for(int i=0; i<v.size(); i++){
        if(v[i] == 1)
            count++;
        else
            count = 0;
        res = max(res, count);
    }
    return res;
}

int main(){
    vector<int>v = {1, 1, 0, 1, 1, 1};
    int ans = solve(v);
    cout<<ans;

    return 0;
}