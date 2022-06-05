#include<bits/stdc++.h>
using namespace std;

//BruteForce: TC:O(N^2) + O(NlogN)
vector<vector<int>> solveBrute(vector<vector<int>> &v){
    int n = v.size();
    if(n <= 1) return v;
    sort(v.begin(), v.end()); //nlogn
    vector<vector<int>>res;
    for(int i=0; i<n; i++){
        int a = v[i][0];
        int b = v[i][1];
        for(int j=i+1; j<n; j++){ //(a,b) (c,d)
            int c = v[j][0];
            int d = v[j][1];
            if(b>=c){
                b = max(b, d);
                i = j;
            }
        }
        res.push_back({a, b});
    }
    return res;
}

//Optimal Approach: TC:O(N) + O(NlogN)
vector<vector<int>> solve(vector<vector<int>> &v){
    vector<vector<int>> mergedIntervals;
    if(v.size() <= 1) return v;

    sort(v.begin(), v.end());
    vector<int>pre_intervals = v[0]; //(a,b)
    for(auto it: v){
        if(it[0] <= pre_intervals[1]){  // c <= b
            pre_intervals[1] = max(it[1], pre_intervals[1]);
        }
        else{
            mergedIntervals.push_back(pre_intervals);
            pre_intervals = it;
        }
    }
    mergedIntervals.push_back(pre_intervals);
    return mergedIntervals;
}

int main(){                //intervals
    vector<vector<int>> v = {{1,3}, {2,6}, {8,10}, {15,18}};
    vector<vector<int>>res;
    cout<<solveBrute(v);
    return 0;
}

//chawal, aata, cheeni, arhar dal, namkeem, bhuna chana , dryfruits