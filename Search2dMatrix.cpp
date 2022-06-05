#include<bits/stdc++.h>
using namespace std;

//Brute force TC:O(N*M)
bool solveBrute(vector<vector<int>> &v, int target){
    int n = v.size(), m = v[0].size();
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(v[i][j] == target)
                return true;
        }
    }
    return false;
}

//Better Approach: Applying Binary search in each row since, matrix is row-wise sorted
//TC: (M logN) M=cols, N=rows
// bool solveBetter(vector<vector<int>> &v, int target){
//     int n = v.size(), m = v[0].size();
//     int j=0;
// }

//Optimal approach: Binary search on whole matrix starting from top right, since the row is sorted, col is also sorted
//the worst case in this approach would be the target is at bottom left. So you have to traverse m + n
//TC:O(m+n)
bool solveBS(vector<vector<int>> &v, int target){
    int n = v.size(), m = v[0].size(), i=0, j=m-1;
    while(i<n && j<m){
        if(v[i][j] == target)
            return true;
        else if(v[i][j] > target)
            j--; //go left
        else 
            i++; //go down
    }
    return false;
}

int main(){
    vector<vector<int>> v = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 3;
    // bool res = solveBrute(v, target);
    // bool res = solveBetter(v, target);
    bool res = solveBS(v, target);
    if(res) 
        cout<<"true";
    else cout<<"false";
    return 0;
}