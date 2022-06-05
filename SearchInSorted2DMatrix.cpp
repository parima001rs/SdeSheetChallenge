#include<bits/stdc++.h>
using namespace std;

//bruteForce TC:O(N^2) & SC:O(1)
bool solveBrute(vector<vector<int>>& matrix, int target){
    int n = matrix.size();
    int m = matrix[0].size();
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(matrix[i][j] == target)
                return true;
        }
    }
    return false;
}

//Binary Search TC:O(log(m*n)) & SC:O(1)
bool solveOptimal(vector<vector<int>> &matrix, int target){
    int n = matrix.size(), m = matrix[0].size();
    int i = 0, j = m-1;
    while(i<n && j>=0){
        if(matrix[i][j] == target)
            return true;
        else if(matrix[i][j] < target)
            i++;
        else
            j--;
    }
    return false;
}

int main(){
    vector<vector<int>> matrix = {{1,3,5,7}, {10,11,16,20},{23, 30,34,60}};
    int target = 3;
    // bool ans = solveBrute(matrix, target);
    bool ans = solveOptimal(matrix, target);
    cout<<ans;
    return 0;
}