#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    void helper(vector<int>&arr, int ind, int target, vector<int>& op){
        if(target == 0){
            res.push_back(op);
            return;
        }   

        for(int i=ind; i<arr.size(); i++){
            if(i != ind && arr[i] == arr[i-1]) continue;
            if(arr[ind] > target) break;
            op.push_back(arr[i]);
            helper(arr, i+1, target- arr[i], op);
            op.pop_back();
        }
        
    }

    //Recursion TC:O(2^n * k) 
    //Assume if all the elements in the array are unique then the 
    // no. of subsequence you will get will be O(2^n). 
    // We also add the op to our res when we reach the base case that will take
    // k = avg. space for the ds
    // single element can be selected only once
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