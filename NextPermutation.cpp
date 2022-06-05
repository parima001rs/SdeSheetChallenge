#include<bits/stdc++.h>
using namespace std;

//Evaluate all possible permutations using recursion, linearly traverse to print next permutation
// TC = 0(n!)[to generate all possible permutations] + 0(nlogn)[for sorting] + 0(n)[for finding next greater permutation]
void permute(vector<int>&v, int ind, vector<vector<int>> &op){
    if(ind == v.size()){
        op.push_back(v);
        return;
    }
    for(int i=ind; i<v.size(); i++){
        if(ind != i && v[ind] == v[i]){
            continue;
        }
        swap(v[i], v[ind]);
        permute(v, ind+1, op);
        swap(v[i], v[ind]); //backtracking
    }
}
void nextPermutationBrute(vector<int> &v){
    vector<vector<int>>op;
    permute(v, 0, op);
    sort(op.begin(), op.end());
    int n = op.size();

    for(int i=0; i<n-1; i++){
        if(op[i] == v){
            v = op[i+1];
            return;
        }
    }
    v = op[0]; //if(v == last ele of op)
}



//=====================================================//
//Using inbuilt function next_permutation
void nextPermutationSTL(vector<int> &v){
    next_permutation(v.begin(), v.end());
    // for(int i=0; i<v.size(); i++)
    //     cout<<v[i]<<" ";
}


//=====================================================//
// peak element   -->   5  \
// break point(i) --> 3   4 \ <-- index j
//                  1       2\

//Optimal Approach O(N)
void nextPermutation(vector<int> &v){
    int n = v.size();
    int i, j;
    for(int i=n-2; i>=0; i--){
        if(v[i] < v[i+1])
            break;
    }
    // if there is no break element, i.e. given is the last permutation
    if(i<0){
        reverse(v.begin(), v.end());
    }

    else{
        for(int j=n-1; j>=0; j--){
            if(v[j] > v[i])
                break;
        }
        swap(v[i], v[j]);
        reverse(v.begin()+i+1, v.end());
    }
}

int main(){
    vector<int>v = {1, 2, 3};
    // nextPermutationSTL(v);
    // nextPermutationBrute(v);
    nextPermutation(v);
    for(auto &it: v)
        cout<<it<<" ";
    return 0;
}