#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    //Kadane's Algo TC:O(N^2) & SC:O(1)
    int solveBrute(vector<int> &arr, int k){
        int n = arr.size(), count = 0;
        for(int i=0; i<n; i++){
            int xorSum = 0;
            for(int j=i; j<n; j++){
                xorSum = xorSum ^ arr[j];
                if(xorSum == k)
                    count++;
            }
        }
        return count;
    }

    //Hashing TC:O(NlogN) & SC:O(N)
    int solveOptimal(vector<int> &arr, int k){
        int n = arr.size(), count = 0, xorr = 0;
        map<int, int>m;
        for(int it: arr){
            xorr = xorr ^ it;
            if(xorr == k)
                count++;
            if(m.find(xorr^k) != m.end())
                count += m[xorr^k];
            m[xorr]++;
        }
        return count;
    }

};

int main(){
    Solution obj;
    vector<int> arr = {4, 2, 2, 6, 4};
    int k = 6;
    int ans = obj.solveOptimal(arr, k);
    cout<<ans;
    return 0;
}