#include<bits/stdc++.h>
using namespace std;

//Brute force ~ 1. Generate all possible substrings
//              2. return the max length of substring

class Solution{
    public:
    //HashSet TC:O(N^2) & SC:O(N)
    int solveBrute(string &str){
        int n = str.length(), maxAns = 0;
        for(int i=0; i<n; i++){
            unordered_set<int>set;
            for(int j=i; j<n; j++){
                if(set.find(str[j]) != set.end()){
                    maxAns = max(maxAns, j-i);
                    break; // to avoid repeating chars
                }
                set.insert(str[j]);
            }
        }
        return maxAns;
    }

    //Optimised Approach TC:O(2*N) & SC:O(N)
    int solveBetter(string &str){
        int maxAns = INT_MIN;
        unordered_set<int>set;
        int l = 0;
        for(int r=0; r<str.length(); r++){
            if(set.find(str[r]) != set.end()){
                while(l<r && set.find(str[r]) != set.end()){
                    set.erase(str[l]);
                    l++;
                }
            }
            set.insert(str[r]);
            maxAns = max(maxAns, r-l+1);
        }
        return maxAns;
    }

    //Optimal Approach TC:O(N) & SC:O(N)
    int solveOptimal(string &str){
        vector<int>mpp(256, -1);
        int left = 0, right = 0;
        int n = str.size();
        int len = 0;
        while(right < n){
            if(mpp[str[right]] != -1)
                left = max(mpp[str[right]] +1 , left);
            
            mpp[str[right]] = right;
            len = max(len, right - left + 1);
            right++;
        }
        return len;
    }
};

int main(){
    Solution obj;
    string str = "abcabcbb";
    // int ans = obj.solveBrute(str);
    // int ans = obj.solveBetter(str);
    int ans = obj.solveOptimal(str);
    cout<<ans;
    return 0;
}