#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    //BruteForce TC:O(N^2) & SC:O(1)
    int solveBrute(vector<int> &arr){
        int n = arr.size(), maxStreak = 0;
        for(int i=0; i<n; i++){
            int sum = 0;
            for(int j=i; i<n; i++){
                sum += arr[i];
                if(sum == 0)
                    maxStreak = max(sum, maxStreak);
            }
        }
        return maxStreak;
    }

    //Hashmap Approach TC:O(NlogN) & SC:O(N)
    int solveOptimal(vector<int> &arr){
        int n = arr.size();
        unordered_map<int, int>m;
        int maxi = 0, sum = 0;
        for(int i=0; i<n; i++){
            sum += arr[i];
            if(sum == 0)
                maxi = i+1;
            else{
                if(m.find(sum) != m.end()){
                    maxi = max(maxi, i-m[sum]); //length (right ind - left ind)
                }
                else{
                    m[sum] = i; 
                }
                return maxi;
            }
        }
    }
};

int main(){
    Solution obj;
    vector<int> arr = {15, -2, 2, -8, 1, 7, 10, 23};
    int ans = obj.solveOptimal(arr);
    cout<<ans;
    return 0;
}