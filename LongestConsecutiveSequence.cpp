#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    //BruteForce TC:O(NlogN) + O(N) & SC:O(N) ~ mergeSort
    int solveBrute(vector<int> &arr){
        int n = arr.size(), currStreak = 1, maxStreak = 0;
        if(n == 0) return 0;
        sort(arr.begin(), arr.end()); //O(NlogN)
        for(int i=0; i<n; i++){ //O(N)
            if(arr[i+1] == arr[i]+1){
                currStreak += 1;
            }
            else if(arr[i] == arr[i+1]){
                continue;
            }
            else{
                currStreak = 1;
            }
            maxStreak = max(currStreak, maxStreak);
        }
    maxStreak = max(currStreak, maxStreak);
    return maxStreak;
    }

    //Hashing TC:O(3N) ~ O(N) & SC:O(N)
    int solveOptimal(vector<int> &nums){
        set<int> hashSet;
        for(int num: nums){
            hashSet.insert(num);
        }
        int maxStreak = 0;
        for(int num: nums){
            if(!hashSet.count(num-1)){
                int currNum = num;
                int currStreak = 1;
                while(hashSet.count(num+1)){
                    currNum += 1;
                    currStreak += 1;
                }
                maxStreak = max(currStreak, maxStreak);
            }
        }
        return maxStreak;
    }
};

int main(){
    Solution obj;
    vector<int>arr = {100, 4, 200, 1, 3, 2};
    int ans = obj.solveOptimal(arr);
    cout<<ans;
    return 0;
}