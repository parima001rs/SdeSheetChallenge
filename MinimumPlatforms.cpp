#include<bits/stdc++.h>
using namespace std;

//Optimal TC:O(n) & SC:O(1)
int solve(vector<int> &arr, vector<int> &dep, int n){
    int count = 1, res = 1;
    sort(arr.begin(), arr.end()); //O(nlogn)
    sort(dep.begin(), dep.end()); //O(nlogn)

    int i=1, j=0;
    while(i<n && j<n){ //O(n)
        if(arr[i] <= dep[j]){
            count++;
            i++;
        }
        else{
            count--;
            j++;
        }
        res = max(res, count);
    }
    return res;
}

int main(){
    int n = 6;
    vector<int>arr = {900, 940, 950, 1100, 1500, 1800};
    vector<int>dep = {910, 1200, 1120, 1130, 1900, 2000};
    

    int ans = solve(arr, dep, n);
    cout<<ans;

    return 0;
}