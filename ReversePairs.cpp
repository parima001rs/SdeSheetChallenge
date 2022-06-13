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

    //MergeSort TC:O(NlogN) + O(N) + O(N) & SC:O(N)
    //            merge sort-----|   Comparison
    int merge(vector<int> &v, int left, int mid , int right){
        int count = 0;
        int j = mid + 1;
        for(int i=left; i<=mid; i++){
            while(j <= right && v[i] > 2LL * v[j]){ //j++ if any of these conditions go false
                j++;
            }
            count += (j - (mid+1));
        }

        vector<int> temp;
        int low = left, high = mid+1;
        while(low <= mid && high <= right){
            if(v[low] <= v[high]){
                temp.push_back(v[low++]);
            }
            else{
                temp.push_back(v[high++]);
            }
        }

        while(low <= mid){
            temp.push_back(v[low++]);
        }
        while(right <= high){
            temp.push_back(v[high++]);
        }
        for(int i=left; i<=right; i++){
            v[i] = temp[i-low];
        }
        return count;
    }

    int merge_sort(vector<int> &v, int left, int right){
        int mid , count = 0;
        if(right > left){
            mid = (right + left)/2;
            count += merge_sort(v, left, mid);
            count += merge_sort(v, mid+1, right);
            count += merge(v, left, mid+1, right);
        }
        return count;
    }

    int solveOptimal(vector<int> &v){
        int temp[v.size()];
        return merge_sort(v, 0, v.size()-1);
    }
};


int main(){
    Solution obj;
    vector<int> v = {6, 4, 8, 2, 1, 3};
    int ans = obj.solveOptimal(v);
    cout<<ans;
}