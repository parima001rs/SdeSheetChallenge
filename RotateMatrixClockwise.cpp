#include<bits/stdc++.h>
using namespace std;

void solve(int n, int m, int mat[4][4]){
    int row = 0, col = 0, lastRow = n, lastCol = m;
    int prev, curr;

    while(row < lastRow && col < lastCol){
        if(row + 1 == lastRow || col + 1 == lastCol) break;
        prev = mat[row+1][col];
        for(int i=col; i<lastCol; i++){
            curr = mat[row][i];
            mat[row][i] = prev;
            prev = curr;
        }
        row++;
        for(int i=row; i<lastRow; i++){
            curr = mat[i][lastCol-1];
        }
    }
}

int main(){
    int mat[4][4] = { {1,  2,  3,  4}, 
			        {5,  6,  7,  8}, 
			        {9,  10, 11, 12}, 
			        {13, 14, 15, 16} }; 

	solve(4,4,a); 
    return 0; 
}