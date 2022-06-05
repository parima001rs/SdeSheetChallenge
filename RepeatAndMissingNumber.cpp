#include<bits/stdc++.h>
using namespace std;

//Bruteforce TC:O(N+N) & SC:O(N) using count sort
vector<int> solveBrute(vector<int> &v){
    vector<int> count(v.size(), 0), ans;
    for(int i=0; i<v.size(); i++){ //storing frequency of each element
        count[v[i]]++;
    }
    for(int i=1; i<=v.size()+1; i++){
        if(count[i] > 1)
            ans.push_back(i); //repeated
        else if(count[i] == 0)
            ans.push_back(i); //missing
    }
    return ans;
}

//Better Approach TC:O(N) & SC:O(1) using maths
vector<int> solveBetter(vector<int> &v){
    long long int n = v.size();
    long long int S = (n * (n+1))/2;
    long long int P = (n*(n+1)*(2*n+1))/6;
    long long int missing = 0, repeating = 0;

    for(int i=0; i<n; i++){
        S -= (long long int)v[i];
        P -= (long long int)v[i] * (long long int)v[i];
    }

    missing = (S + P/S)/2;
    repeating = missing - S;
    return {repeating, missing};
}

//Xor Approach TC:O(N) & SC:O(1)
vector<int> solveOptimal(vector<int> &v){
    int xor1;
    int set_bit_no;

    int i;
    int x = 0; //missing
    int y = 0; //repeated
    int n = v.size();

    xor1 = v[0];
    
    //get the xor of all the array elements
    for(i=1; i<n; i++){
        xor1 = xor1 ^ v[i];
    }

    //Xor the previous result with numbers from 1 to n
    for(i=1; i<=n; i++){
        xor1 = xor1 ^ i;
    }
    //get the rightmost set bit in set_bit_no
    set_bit_no = xor1 & ~(xor1 - 1);

    //dividing in two sets/buckets
    for(i=0; i<n; i++){
        if(v[i] & set_bit_no){
            //belongs to first set
            x = x ^ v[i];
        }
        else{
            y = y ^ v[i];
        }
    }

    //xoring with all numbers from 1 to n
    for(i=1; i<=n; i++){
        if(i & set_bit_no){
            x = x ^ i;
        }
        else{
            y = y ^ i;
        }
    }

    int x_count = 0;
    for(i=0; i<n; i++){
        if(v[i] == x)
            x_count++;
    }

    if(x_count == 0)
        return {y, x};
    return {x, y};
} 

int main(){
    vector<int> v;
    v = {3, 1, 2, 5, 3};
    vector<int> res = solveBrute(v);
    cout<<"Repeated: "<<res[0]<<" "<<"Missing: "<<res[1];
    return 0;
}
