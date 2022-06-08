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

    //Optimised Approach TC:O() & SC:O()
    int solveBetter(string &str){
        
    }
};

int main(){
    Solution obj;
    string str = "abcabcbb";
    int ans = obj.solveBrute(str);
    cout<<ans;
    return 0;
}