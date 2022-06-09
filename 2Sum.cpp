#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    //Bruteforce TC:O(N^2) & SC:O(2)
    vector<int> solveBrute(vector<int> &arr, int target){
        vector<int>v;
        for(int i=0; i<arr.size(); i++){
            for(int j=i+1; i<arr.size(); i++){
                if(arr[i] + arr[j] == target)
                    v.push_back(i);
                    v.push_back(j);
                    break;
            }
            if(v.size() == 2) break;
        }
        return v;
    }

    //Hashing TC:O(NlogN) & SC:O(N)
    vector<int> solveOptimal(vector<int> &arr, int target){
        map<int, int>m;
        vector<int>res;
        for(int i=0; i<arr.size(); i++){
            if(m.find(target-arr[i]) != m.end()){
                res.push_back(i);
                res.push_back(m[target-arr[i]]);
                break;
            }
            m[arr[i]] = i;
        }
        return res;
    }

};

int main(){
    Solution obj;
    vector<int> arr = {2, 7, 11, 15};
    int target = 9;
    // vector<int> res = obj.solveBrute(arr, target);
    vector<int> res = obj.solveOptimal(arr, target);
    for(int num: res)
        cout<<num<<" ";
    return 0;
}