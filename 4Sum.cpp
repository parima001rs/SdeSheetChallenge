#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    //BruteForce
    // Time Complexity: O(N log N + N³ logN)
    // Reason: Sorting the array takes N log N and three nested loops will be taking N³ and for binary search, it takes another log N.
    // Space Complexity: O(M * 4), where M is the number of quads

    vector<vector<int>> solveBrute(vector<int> &arr, int target){
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
                        int mid = left + (right - left)/2;
                        if(arr[mid] == ele){
                            vector<int>v(4, 0);
                            v[0] = arr[i];
                            v[1] = arr[j];
                            v[2] = arr[k];
                            v[3] = ele;
                            sort(v.begin(), v.end());
                            s.insert(v);
                        }
                        else if(arr[mid] < ele)
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

    //Optimal TC:O(N^3) & SC:O(M*4)
    vector<vector<int>> solveOptimal(vector<int> &arr, int target){
        vector<vector<int>> res;
        if(arr.empty()) return res;
        int n = arr.size();

        sort(arr.begin(), arr.end());
        for(int i=0; i<n; i++){
            int ele1 = target - arr[i];
            for(int j=i+1; j<n; j++){
                int ele2 = ele1 - arr[j];
                int low = j+1;
                int high = n-1;

                while(low < high){
                    int two_sum = arr[low] + arr[high]; 
                    if(two_sum > ele2)
                        high--;
                    else if(two_sum < ele2)
                        low++;
                    else{
                        vector<int>quad(4, 0);
                        quad[0] = arr[i];
                        quad[1] = arr[j];
                        quad[2] = arr[low];
                        quad[3] = arr[high];
                        res.push_back(quad);

                        while(low < high && arr[low] == quad[2]) ++low;
                        while(low < high && arr[high] == quad[3]) --high;
                    }
                }
                while(j+1 < n && arr[j+1] == arr[j]) ++j;
            }
            while(i+1 <n && arr[i+1] == arr[i]) ++i;
        }
        return res;
    }

};

int main(){
    Solution obj;
    vector<int> arr = {1, 0, -1, 0, -2, 2};
    int target = 0;
    vector<vector<int>> res = obj.solveOptimal(arr, target);
    for(int i=0; i<res.size(); i++){
        for(int j=0; j<res[i].size(); j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}