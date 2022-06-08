#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    //Bruteforce TC:O(N^2) & SC:O(1)
    int solveBrute(vector<int> &v){
        int count = 0, n = v.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(v[i] > 2* v[j])
                    count++;
            }
        }
        return count;
    }   

    int merge(vector<int> &v, int temp[], int left, int mid , int right){
        int count = 0;
        int i = left, j = mid, k = left;
        while(i <= mid && j>= right){
            if(v[i] <= 2*v[j]){
                temp[k++] = v[i++];
            }
            else{
                temp[k++] = v[j++];
                count += mid-i;
            }
        }

        while(i <= mid-1)
            temp[k++] = v[i++];
        while( j <= right)
            temp[k++] = v[j++];
        for(int i=left; i<=right; i++)
            v[i] = temp[i];
        return count;
    }

    int merge_sort(vector<int> &v, int temp[], int left, int right){
        int mid , count = 0;
        if(right > left){
            mid = (right + left)/2;
            count += merge_sort(v, temp, left, mid);
            count += merge_sort(v, temp, mid+1, right);
            count += merge(v, temp, left, mid+1, right);
        }
        return count;
    }

    int solveOptimal(vector<int> &v){
        int temp[v.size()];
        return merge_sort(v, temp, 0, v.size()-1);
    }
};

//LEETCODE SOLUTION
class Solution {
public:
    int count = 0;
    int reversePairs(vector<int>& nums) {
        if(!nums.size()) return 0;
        count = 0;
        mergeSort(nums,0,nums.size()-1);
        return count;
    }
    
    void mergeSort(vector<int>& nums, int l, int r){
        int mid = l + (r-l) /2;
        if(l>=r) return;
        
            mergeSort(nums, l, mid);
            mergeSort(nums, mid+1, r);
            merge(nums, l, mid, r);
            return;
    }
    
    int merge(vector<int>& nums, int start, int mid, int end){
        int l = start, r = mid +1;
        while(l<=mid && r<=end){
            if((long)nums[l] > (long)2* nums[r]){
                count += (mid - l +1);
                r++;
            }
            else{
                l++;
            }
        }
        sort(nums.begin()+ start, nums.begin()+end+1);
        return count;
    }
};

int main(){
    Solution obj;
    vector<int> v = {6, 4, 8, 2, 1, 3};
    int ans = obj.solveBrute(v);
    cout<<ans;
}