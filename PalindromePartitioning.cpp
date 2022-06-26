#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    vector<vector<string>> res;
    bool isPalindrome(string s, int a, int b){
        while(a <= b){
            if(s[a++] != s[b--])
                return false;
        }
        return true;
    }

    void helper(int ind, string s, vector<string>&op){
        if(ind == s.size()){
            res.push_back(op);
            return;
        }

        for(int i=ind; i<s.size(); i++){
            if(isPalindrome(s, ind, i)){
                op.push_back(s.substr(i, i-ind+1));
                helper(i+1, s, op);
                op.pop_back();
            }
        }
    }

    vector<vector<string>> solve(string s){
        vector<string>op;
        helper(0, s, op);
        return res;
    }

};


int main(){
    Solution obj;
    string s = "aab";
    vector<vector<string>>res = obj.solve(s);

    cout<<"[";
    for(int i=0; i<res.size(); i++){
        cout<<"[";
        for(int j=0; j<res[i].size()-1; j++){
            cout<<res[i][j]<<",";
        }
        cout<<res[i][res[i].size()-1];
        cout<<"]";
    }
    cout<<"]";

    return 0;
}