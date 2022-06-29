#include<bits/stdc++.h>
using namespace std;

void helperBrute(string& s, int ind, vector<string>&res){
    if(ind == s.size()){
        res.push_back(s);
        return;
    }
    for(int i=index; i<s.size(); i++){
        swap(s[i], s[ind]);
        helperBrute(s, ind+1, res);
        swap(s[i], s[ind]);
    }
}

//BruteForce using recursion TC:O(N! * N) +O(N! Log N!) & SC: O(N)
//The recursion takes O(N!)  time because we generate every possible permutation and another O(N)  time is required to make a deep copy and store every sequence in the data structure. Also, O(N! Log N!)  time required to sort the data structure
string solveBrute(int n, int k){
   string s;
   vector<string>res;
   for(int i=1; i<=n; i++){
    s.push_back(i+'0');
   }
   helperBrute(s, 0, res);
   sort(res.begin(), res.end());
   auto it = res.begin() + (k-1);
   return *it;
}

//Optimal : must remember intuition
//TC:O(N^2) & SC:O(N)
string solve(int n, int k){
    int fact = 1;
    vector<int> numbers;
    for(int i=1; i<n; i++){
        fact = fact * i;
        numbers.push_back(i);
    }

    numbers.push_back(n);
    string ans = "";
    k = k-1;
    while(true){
        ans = ans + to_string(numbers[k/fact]);
        numbers.erase(numbers.begin() + k/fact);
        if(numbers.size() == 0){
            break;
        }
        k = k %fact;
        fact = fact / numbers.size();
    }
    return ans;
}

int main(){
    int n = 3, k = 3;
    string res = solve(n, k);
    
    cout<<res<<endl;

    return 0;
}