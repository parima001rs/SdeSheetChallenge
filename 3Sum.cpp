#include<bits/stdc++.h>
using namespace std;

//Brute force TC:O(N^3) & SC:O(K*3)

//Optimal TC:O(N^2) & SC:O(M) ~ res
vector<vector<int>> solve(vector<int> &v, int k){
    vector<vector<int>>res;
    sort(v.begin(), v.end());

    for(int i=0; i<v.size()-2; i++){
        int target = k-v[i];
        int low = i+1;
        int high = v.size()-1;
        
        while(low < high){
            int sum = v[low] + v[high];
            if(sum < target)
                low++;
            else if(sum > target)
                high--;
            else{
                vector<int> triplet = {v[i], v[low], v[high]};
                res.push_back(triplet);

                while(low < high && v[low] == triplet[1]) low++;
                while(low < high && v[high] == triplet[2]) high--;
            }
        }
        while(i+1 < v.size() && v[i] == v[i+1]) i++;
    }
    return res;
}

int main(){
    vector<int>v = {-1, 0, 1, 2, -1, -4};
    int k = 0;
    vector<vector<int>> res = solve(v, k);

    for(int i=0; i<res.size(); i++){
        for(int j=0; j<3; j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}