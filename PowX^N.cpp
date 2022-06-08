#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:

    //BruteForce TC:O(N) & SC:O(1)
    double solveBrute(double x, int n){
        double res = 1.0;
        long long n2 = n;
        for(int i=0; i<n; i++){
            res *= n2;
        }
        if(n<0)
            return (double)(1.0)/(double)(res);
        return res;
    }

    //Optimal TC:O(log N) & SC:O(1)
    double solveOptimal(double x, int n){
        double res = 1.0;
        long long n2 = n;
        if(n2 < 0)
            n2 = -1*n2;
        while(n2){
            if(n2%2){
                res = res * x;
                n2 = n2 -1;
            }
            else{
                x = x*x;
                n2 = n2/2;
            }
        }
        if(n<0) 
            res = (double)(1.0)/(double)(res);
        return res;
    }

    
};

int main(){
    Solution obj;
    double x = 2.00000;
    int n = -2;
    double ans = obj.solveBrute(x, n);
    // double ans = obj.solveOptimal(x, n);
    cout<<ans;
    return 0; 
}