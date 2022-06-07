#include<bits/stdc++.h>
using namespace std;

//Brute force TC:O(N^2) & SC:O(1)
int solveBrute(int arr[], int n){
    int majorityCount = n/2;
    for(int i=0; i<n; i++){
        int count = 0;
        for(int j=0; j<n; j++){
            if(arr[j] == arr[i])
                count++;
        }
        if(count > majorityCount){
            return arr[i];
        }
    }
    return -1;
}

//Frequency array/ hashmap to store number of occurences of each ele
// TC:O(NlogN) ~worst case of unordered_map due to colliosions & SC:O(N)
int solveBetter(int arr[], int n){
    unordered_map<int, int> counter;
    for(int i=0; i<n; i++){
        counter[arr[i]]++;
    }

    for(int i=0; i<counter.size(); i++){
        if(counter[arr[i]] > n/2){
            return counter[arr[i]];
        }
    }
    return -1;
}

//Boyer Moore's Voting Algorithm TC:O(N) & TC:O(1)
int solveOptimal(int arr[], int n){
    int count = 0, ele = -1;
    for(int i=0; i<n; i++){
        if(count == 0)
            ele = arr[i];
        if(ele == arr[i]) //don't write else if here
            count++;
        else    
            count--;
    }
    return ele;
}




int main(){
    int arr[] = {1, 1, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    // int ans = solveBrute(arr, n);
    // int ans = solveBetter(arr, n);
    int ans = solveOptimal(arr, n);
    cout<<ans;
    return 0;
}