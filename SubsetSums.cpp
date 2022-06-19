#include<bits/stdc++.h>
using namespace std;

void solve(int ind, vector<int>&arr, vector<int>&ans, int sum){
    if(ind == arr.size()){
        ans.push_back(sum);
        return;
    }

    solve(ind+1, arr, ans, sum+arr[ind]);
    solve(ind+1, arr, n, ans, sum);
}

//TC: O(2^n) + O(2^n log(2^n)) & SC: O(2^n)
vector<int> subsetSum(vector<int> &arr){
    vector<int> ans;
    int sum = 0;
    solve(0, arr, ans, sum);
    return ans;
}

int main(){
    vector<int> arr = {3, 1, 2};
    vector<int> ans = subsetSum(arr);

    sort(ans.begin(), ans.end());
    for(auto sum: ans){
        cout<<sum<<" ";
    }
    cout<<endl;

    return 0;
}