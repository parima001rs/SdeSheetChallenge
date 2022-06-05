#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //Recursive Approach TC:O(2^m+n) & SC:O(m+n)
    int countPathsBrute(int i, int j, int n, int m){
        if(i == n-1 && j == m-1)
            return 1;
        if(i>=n || j>=m)
            return 0;
        else    
            return countPathsBrute(i+1, j, n, m) + countPathsBrute(i, j+1, n, m);
    }
    int solveBrute(int n, int m){
        return countPathsBrute(0, 0, n, m);
    }

    //DP Memoization TC:O(m*n) & SC:O(m*n)
    int countPathsBetter(int i, int j, int n, int m, vector<vector<int>>&t){
        if(i == n-1 && j == m-1)
            return 1;
        if(i >= n || j >= m)
            return 0;
        else t[i][j] = countPathsBetter(i+1, j, n, m, t) + countPathsBetter(i, j+1, n, m, t);
    }

    int solveBetter(int n, int m){
        vector<vector<int>> t(m+1, vector<int>(n+1, -1));
        int num = countPathsBetter(0, 0, n, m, t);
        if(m == 1 && n == 1)
            return num;
        return t[0][0];
    }

    //DP Tabulation
    int solveBetterdp(int n, int m){
        vector<vector<int>> dp(n, vector<int>(m,1));
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
            return dp[m-1][n-1];
        }
    }
    //Combinatorics Solution TC:O(min(n, m)) & SC:O(1) refer https://leetcode.com/problems/unique-paths/discuss/1581998/C%2B%2BPython-5-Simple-Solutions-w-Explanation-or-Optimization-from-Brute-Force-to-DP-to-Math
    int solveOptimal(int n, int m){
        long ans = 1;
        for(int i = m+n-2, j=1; i >= max(m, n); i--, j++){
            ans = (ans* i)/j;
        }
    return ans;
    }
};


int main(){
    Solution obj;
    int totalCount = obj.solveBrute(3,7);
    // int totalCount = obj.solveOptimal(3,7);
    cout<<totalCount;
}