#include<bits/stdc++.h>
using namespace std;

// TC: O(n) +O(n log n) + O(n) ~ O(n log n)
// SC: O(n)
int solve(vector<int>&start, vector<int>&end, int n){
    vector<pair<int, int>>v;
    for(int i=0; i<n; i++){
        v.push_back({end[i], start[i]});
    }
    int count = 1;

    sort(v.begin(), v.end());
    int e = v[0].first;
    for(int i=0; i<n; i++){
        if(v[i].second > e){
            e = v[i].first;
            count++;
        }
    }
    return count;
}

int main(){
    vector<int>start = {1, 3, 0, 5, 8, 5};
    vector<int>end = {2, 4, 6, 7, 9, 9};
    int n = 6;

    int ans = solve(start, end, n);
    cout<<ans;

    return 0;
}

