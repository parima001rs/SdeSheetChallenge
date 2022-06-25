#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    void helper(vector<int>arr, int ind, int target, vector<int> op){
        if(ind == arr.size()){
            if(target == 0){
                res.push_back(op);
            }
            return;
        }

        vector<int> op1 = op;
        vector<int> op2 = op;
        for(int i=ind; i<arr.size(); i++){
            if(i != ind && arr[i] == arr[i-1]) continue;
            if(arr[ind] > target) break;
            op1.push_back(arr[ind]);
            helper(arr, ind+1, target- arr[ind], op1);
            helper(arr, ind+1, target, op2);
        }
        
    }

    //Recursion TC:O(2^t * k) where t is the target, k is the avg length
    // single element can be selected multiple time
    // SC: O(k * x) x = no. of the combinations
    vector<vector<int>> solve(vector<int>& arr, int target){
        sort(arr.begin(), arr.end());
        vector<int>op;
        helper(arr, 0, target, op);
        return res;
    }

};

int main(){
    Solution obj;
    vector<int> arr = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    
    vector<vector<int>> v = obj.solve(arr, target);
    cout<<"[";
    for(int i=0; i<v.size(); i++){
        cout<<"[";
        for(int j=0; j<v[i].size()-1; j++){
            cout<<v[i][j]<<",";
        }
        cout<<v[i][v[i].size()-1];
        cout<<"]";
    }
    cout<<"]";

    return 0;
}