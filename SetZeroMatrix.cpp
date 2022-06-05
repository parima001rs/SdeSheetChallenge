#include<bits/stdc++.h>
using namespace std;


//BRUTE FORCE TC: O(N*M) * O(N+M) & SC: O(1)
void setZeroesBrute(vector<vector<int>> &matrix){
    int rows = matrix.size(), cols = matrix[0].size();
    //TC: O(N*M) * O(N+M)
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(matrix[i][j] == 0){
                //traversing left side of row 
                int ind = i-1;
                while(ind >= 0) {
                    if(matrix[ind][j] != 0)
                        matrix[ind][j] = -1;
                    ind--;
                }
                //traversing right side of row
                ind = i+1;
                while(ind < rows){
                    if(matrix[ind][j] != 0)
                        matrix[ind][j] = -1;
                    ind++;
                }
                //traversing upper side of col
                ind = j-1;
                while(ind >= 0){
                    if(matrix[i][ind] != 0)
                        matrix[i][ind] = -1;
                    ind--;
                }
                //traversing bottom part of col
                ind = j+1;
                while(ind < cols){
                    if(matrix[ind][j] != 0)
                        matrix[ind][j] = -1;
                    ind++;
                }

            }
        }
    }

    //traversing for converting every -1 into 0  TC: O(N*M)
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(matrix[i][j] == -1)
                matrix[i][j] = 0;
        }
    }
}

//BETTER APPROACH TC:O(N*M) + O(N*M) SC:O(N+M)
void setZeroesBetter(vector<vector<int>> &matrix){
    int rows = matrix.size(), cols = matrix[0].size();
    vector<int> dummyRow(rows, -1), dummyCol(cols, -1);
    //TC:O(N*M)
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(matrix[i][j] == 0){
                dummyRow[i] = 0;
                dummyCol[j] = 0;
            }
        }
    }
    //TC:O(N*M)
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(dummyRow[i] == 0 || dummyCol[j] == 0){
                matrix[i][j] = 0;
            }
        }
    }
}

//OPTIMAL APPROACH TC:O(N*M)+ O(N*M) SC:O(1)
void setZeroesOptimal(vector<vector<int>> &matrix){
    int rows = matrix.size(), cols = matrix[0].size();
    bool col_0 = true;
    // TC:O(N*M)
    for(int i=0; i<rows; i++){
            if(matrix[i][0] == 0) col_0 = false;
            for(int j=1; j<cols; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        
    // TC:O(N*M)
    for(int i=rows-1; i>=0; i--){
        for(int j=cols-1; j>=1; j--){
            if(matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        } //second for loop terminates here IMP
        if(!col_0){
            matrix[i][0] = 0;
        }
    }
}

int main(){
    vector<vector<int>> arr;
    arr = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    // setZeroesBrute(arr);
    // setZeroesBetter(arr);
    setZeroesOptimal(arr);
    cout<<"The final Matrix is" << endl;
    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<arr[0].size(); j++){
            cout<<arr[i][j] << " ";
        }
        cout<<endl;
    }
    return 0;
}