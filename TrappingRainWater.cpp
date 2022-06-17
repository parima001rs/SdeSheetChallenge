#include<bits/stdc++.h>
using namespace std;

//BruteForce TC:O(N*N) & SC:O(1)
//min((left[i], right[i]) - a[i])
int solve(vector<int>& h){
    int n = h.size();
    int waterTrapped = 0;
    
    for(int i=0; i<n; i++){
        int j=i;
        int leftMax = 0, rightMax = 0;
        while(j < n){
            leftMax = max(leftMax, h[j]);
            j++;
        }
        j = i;
        while(j >= 0){
            rightMax = max(rightMax, h[j]);
            j--;
        }
        waterTrapped += min(leftMax, rightMax) - h[i];
    }
    return waterTrapped;
    
}

// Better~ prefix sum & Suffix sum TC:O(N) & SC:O(2N)
int solveBetter(vector<int>& h){
    int n = h.size();
    int ans = 0;
    vector<int> leftMax(n, 0),rightMax(n, 0);

    leftMax[0] = h[0];
    rightMax[n-1] = h[n-1];

    if(n == 0) return 0;

    for(int i=1; i<n; i++){
        leftMax[i] = max(leftMax[i-1], h[i]);
    }

    for(int i=n-2; i>=0; i--){
        rightMax[i] = max(rightMax[i+1], h[i]);
    }

    for(int i=0; i<n; i++){
        ans += min(leftMax[i], rightMax[i]) - h[i];
    }
    return ans;
}

//Optimal~ 2Pointer TC:O(N) & SC:O(1)
int solveOptimal(vector<int>& h){
    int n = h.size();
    int l = 0, r = n-1, ans = 0;
    int leftMax = 0, rightMax = 0;

    while(l<=r){
        if(h[l] <= h[r]){ //min(leftMax, rightMax)
            if(h[l] > leftMax) leftMax = h[l];
            else ans += leftMax - h[l];
            l++;
        }
        else{
            if(h[r] > rightMax) rightMax = h[r];
            else ans += rightMax - h[r];
            r--;
        }
    }
    return ans;
}



int main(){
    vector<int> h = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    // int ans = solve(h);
    // int ans = solveBetter(h);
    int ans = solveOptimal(h);
    cout<<ans;

    return 0;
}