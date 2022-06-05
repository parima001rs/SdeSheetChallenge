#include<bits/stdc++.h>
using namespace std;

//BruteForce TC: O(N^2)
int solveBrute(vector<int> &v){
    int n = v.size(), sum, res = INT_MIN;
    for(int i=0; i<n; i++){
        sum = 0;
        for(int j=i; j<n; j++){
            sum += v[j];
            res = max(res, sum);
        }
    }
    return res;
}

//OPTIMAL APPROACH: Kadane's Algorithm (Iterative DP Algo) TC: O(N)
int solveKadane(vector<int> &v){
    int sum = 0, res = INT_MIN;
    for(auto &it: v){
        sum += it;
        res = max(res, sum);
        if(sum < 0) sum = 0;   //if -ve sum , make it 0
    }
    return res;
}

//===============================================================//
//ANOTHER APPROACHES

// Divide & Conquer TC:O(NlogN) & SC:O(NlogN)
int solveDNC(vector<int> &v, int l, int r){
    if(l > r) return INT_MIN;
    int mid = (l+r)/2, leftSum = 0, rightSum = 0, curSum = 0;

    //l<---- mid
    for(int i=mid-1; i>=l; i--){
        curSum += v[i];
        leftSum = max(leftSum, curSum);
    }

    curSum = 0;
    //mid------->r
    for(int i=mid+1; i<=r; i++){
        curSum += v[i];
        rightSum = max(rightSum, curSum);
    }
    return max({solveDNC(v, l, mid-1), solveDNC(v, mid+1, r), leftSum+v[mid]+rightSum});
}

int solveDivideNConquer(vector<int> &v){
    return solveDNC(v, 0, v.size()-1);
}

//=========================================================//
// Recursion approach TC:O(N^2) & SC:O(N)
int solveRecur(vector<int> &v, int i, bool mustPick){
    if(i >= v.size()){
        return mustPick ? 0 : INT_MIN;
    }

    if(mustPick)
        return max(0, v[i] + solveRecur(v, i+1, true));
    return max(solveRecur(v, i+1, false), v[i]+ solveRecur(v, i+1, true));
}

int solveRecursion(vector<int> &v){
    return solveRecur(v, 0, false);
}
// DP TC:O(N) & SC:O(N)

//Driver Code
int main(){
    vector<int>v = {-2,1,-3,4,-1,2,1,-5,4};
    // cout<<solveBrute(v);
    // cout<<solveKadane(v);
    // cout<<solveDivideNConquer(v);
    cout<<solveRecursion(v);
    return 0;
}