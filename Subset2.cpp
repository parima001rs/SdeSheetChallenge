#include<bits/stdc++.h>
using namespace std;

// BruteForce : Generate powerset,  hash them and return unique subsets
// TC: O(2^n * (k log(x))
// O(2^n) for generating all subsets, k* log( x)  to insert every 
// combination of average length k in a set of size x. 
// After this, we have to convert the set of combinations 
// back into a list of list /vector of vectors which takes more time. 
class Solution {
    public:
    vector<vector<int>> res;
    set<vector<int>> s;
    void helperBrute(vector<int> nums, vector<int> op){
        if(nums.size() == 0){
            if(s.find(op) == s.end()){
                s.insert(op);
                res.push_back(op);
            }
            return;
        }

        vector<int>op1 = op;
        vector<int>op2 = op;
        op2.push_back(nums[0]);
        nums.erase(nums.begin() + 0);

        helperBrute(nums, op1);
        helperBrute(nums, op2);
    }

    vector<vector<int>> solveBrute(vector<int> &nums){
        vector<int> op;
        sort(nums.begin(), nums.end());
        helperBrute(nums, op );
        return res;
    }

};


// Optimised Recursion
// O(2^n) for generating every subset and O(k) to insert
// every subset in another data structure if the average 
// length of every subset is k. Overall O(k * 2^n).
// class Solution {
//     private:

//     void helper(vector<int>& nums, vector<int>& op, int ind, vector<vector<int>> &res){
//         res.push_back(op);
//         for(int i= ind; i< nums.size(); i++){
//             if(i != ind && nums[i] == nums[i-1]) continue;

//             op.push_back(nums[i]);
//             helper(nums, op, i+1, res);
//             op.pop_back();
//         }
//     }

// public:
//     vector<vector<int>> solveOptimal(vector<int> &nums){
//         vector<vector<int>> res;
//         vector<int> op;
//         sort(nums.begin(), nums.end());
//         helper(nums, op, 0, res);
//         return res;
//     }
// };



int main(){
    vector<int> nums = {1, 2, 2};
    Solution obj;
    vector<vector<int>> res = obj.solveBrute(nums);

    cout<<"The unique subsets are "<<endl;
    cout<<"[";
    for(int i=0; i<res.size(); i++){
        cout<<"[";
        for(int j=0; j<res[i].size(); j++){
            cout<<res[i][j]<<" ";
        }
        cout<<"]";
    }
    cout<<"]";

    return 0;
}