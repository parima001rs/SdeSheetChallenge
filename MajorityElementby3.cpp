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
    int c1 = 0, c2 = 0, ele1 = -1, ele2 = -1;
    for(int i=0; i<n; i++){
        if(c1 == 0){
            ele1 = arr[i];
            c1 = 1;
        }
        if(c2 == 0){
            ele2 = arr[i];
            c2 = 1;
        }
        if(ele1 == arr[i])
            c1++;
        if(ele2 == arr[i])
            c2++;
        else{
            c1--;
            c2--;
        }
    }
    int ans = -1;
    c1 = c2 = 0;
    for(int i=0; i<n; i++){
        if(arr[i] == ele1)
            c1++;
        else if(arr[i] == ele2)
            c2++;
    }

    if(c1 > n/3)
        ans = ele1;
    ans = ele2;
    
    return ans;
}


int main(){
    int arr[] = {3,2,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    // int ans = solveBrute(arr, n);
    // int ans = solveBetter(arr, n);
    int ans = solveOptimal(arr, n);
    cout<<ans;
    return 0;
}