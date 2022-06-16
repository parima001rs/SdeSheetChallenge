#include<bits/stdc++.h>
using namespace std;

//storing first row in last col of dummy matrix
//TC:O(N^2) & SC: O(N^2)
void solveBrute(vector<vector<int>> &v){
    int n = v.size();
    vector<vector<int>> res(n, vector<int>(n, 0));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            res[j][n-i-1] = v[i][j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            v[i][j] = res[i][j];
        }
    }
}

//Optimal Approach: TC:O(N^2) & SC:O(1)
void solveOptimal(vector<vector<int>> &v){
    int n = v.size();
    //transpose ~ row->col & col->row
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            swap(v[i][j], v[j][i]);
        }
    }

    // reversing each row
    for(int i=0; i<n; i++)
        reverse(v[i].begin(), v[i].end());
}

int main(){
    vector<vector<int>>v = {{1,2,3}, {4,5,6}, {7,8,9}};
    solveBrute(v);
    // solveOptimal(v);
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<v[0].size(); j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}