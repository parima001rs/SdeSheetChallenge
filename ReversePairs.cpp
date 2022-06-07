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

int main(){
    Solution obj;
    vector<int> v = {6, 4, 8, 2, 1, 3};
    int ans = obj.solveBrute(v);
    cout<<ans;
}