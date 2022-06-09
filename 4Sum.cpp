#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    //BruteForce TC:O() & SC:O()
    vector<vector<int>> solveBrute(vector<int> &arr, int target){
        // vector<vector<int>> res;
        int n = arr.size();

        sort(arr.begin(), arr.end());
        set<vector<int>> s;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                for(int k=j+1; k<n; k++){
                    int ele = (long long)target - ((long long)arr[i] + (long long)arr[j] + (long long)arr[k]);
                    int left = k+1;
                    int right = n-1;
                    while(left < right){
                        int mid = (left + right)/2;
                        if(mid == ele){
                            vector<int>v(4, 0);
                            v[0] = arr[i];
                            v[1] = arr[j];
                            v[2] = arr[k];
                            v[3] = ele;
                            sort(v.begin(), v.end());
                            s.insert(v);
                        }
                        else if(mid < ele)
                            left = mid+1;
                        else   
                            right = mid-1;
                    }

                }
            }
        }
        vector<vector<int>> res(s.begin(), s.end());
        return res;
    }

    //Optimal TC:O() & SC:O() 
};

int main(){
    Solution obj;
    vector<int> arr = {1, 0, -1, 0, -2, 2};
    int target = 0;
    vector<vector<int>> res = obj.solveBrute(arr, target);
    for(int i=0; i<res.size(); i++){
        for(int j=0; j<res[i].size(); j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}