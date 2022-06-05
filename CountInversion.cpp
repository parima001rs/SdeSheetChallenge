#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Brute force TC:O(N^2) & SC:O(1)
int solveBrute(vector<int> &arr){
    int count = 0;
    for(int i=0; i<arr.size(); i++){
        for(int j=i+1; j<arr.size(); j++){
            if(arr[i] > arr[j])
                count++;
        }
    }
    return count;
}

//MergeSort TC:O(NlogN) & SC:O(N)
int merge(vector<int> &arr, int temp[], int left, int mid, int right){
    int inv_count = 0;
    int i = left, j = mid, k = left;
    while((i<=mid-1) && (j<=right)){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }
        else{
            temp[k++] = arr[j++];
            inv_count += mid-i;
        }
    }

    while(i <= mid-1)
        temp[k++] = arr[i++];
    while(j <= right)
        temp[k++] = arr[j++];
    for(i=left; i<=right; i++)
        arr[i] = temp[i];
    return inv_count;
}

int merge_sort(vector<int> &arr, int temp[], int left, int right){
    int mid, inv_count = 0;
    if(right > left){
        mid = (right + left) /2;
        inv_count += merge_sort(arr, temp, left, mid);
        inv_count += merge_sort(arr, temp, mid+1, right);
        inv_count += merge(arr, temp, left, mid+1, right);
    }
    return inv_count;
}

int solveOptimal(vector<int> &arr){
    int n = arr.size();
    int temp[n];
    return merge_sort(arr, temp, 0, n-1);
}

//Fenwick Tree Approach

int main(){
    vector<int> arr = {8, 4, 2, 1};
    // int ans = solveBrute(arr);
    int ans  = solveOptimal(arr);
    cout<<ans;
    return 0;
}