#include<bits/stdc++.h>
using namespace std;

//BruteForce~HashSet TC:O(NlogN)+O(N) & SC:O(N)
//O(N) ~ traversing array & O(logN) ~inserting in set & O(N) ~inserting in array
int solve(vector<int>& v){
    unordered_set<int> s;
    for(int i=0; i<v.size(); i++){
        s.insert(v[i]);
    }
    int k = s.size();
    int j =0;
    for(int it: s){
        v[j++] = it;
    }
    return k;
}

//Optimal~2pointer TC:O(N) & SC:O(1)
int solveOptimal(vector<int>& v){
    if(v.size() == 0) return 0;
    int i=0;

    for(int j=1; j<v.size(); j++){
        if(v[j] != v[i]){ //when diff 
            i++;
            v[i] = v[j];
        }
    }
    // for(int it: v) cout<<it;
    return i+1;
}

int main(){
    vector<int> v = {0,0,1,1,1,2,2,3,3,4};
    int ans = solve(v);
    // int ans = solveOptimal(v);
    cout<<ans;

    return 0;
}