#include<bits/stdc++.h>
using namespace std;

// //for printing whole pascal triangle if number of rows is given
// // TC: O(N^2) , SC:O(N^2) for storing soln
vector<vector<int>> printPascalTriangle(int n)
{
    vector<vector<int>>v(n);
    for(int i=0; i<n; i++){
        v[i].resize(i+1); //increasing cols per row
        v[i][0] = v[i][i] = 1;

        for(int j=1; j<i; j++)
            v[i][j] = v[i-1][j-1] + v[i-1][j];
    }
    return v;
}

//without resize function and printing in function only
vector<vector<int>> printPascal(int n)
{
	vector<vector<int>> res;
	for (int i = 0; i < n; i++) {
		vector<int> row(i + 1, 1);
		for (int j = 1; j < i; j++) {
			row[j] = res[i - 1][j] + res[i - 1][j - 1];
		}
		res.push_back(row);
	}
	return res;
}


int main(){
    int n;
    cin>>n;
    // auto ans = printPascal(n);// without resize() funcn
    auto ans = printPascalTriangle(n);
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            cout<<ans[i][j] <<" ";
        }
        cout<<endl;
    }
    return 0;
}

//=====================================================//
//for evaluating single element
//TC: O(N) & SC: O(1)
int fact(int n){
    int res = 1;
    for(int i=2; i<=n; i++){
        res = res * i;
    }
    return res;
}

int main(){
    int r, c; //nCr
    cin>>r>>c;
    r = r-1, c= c-1;
    int res = fact(r) / (fact(c) * fact(r-c));
    cout<<res;
    return 0;
}


//=========================================================//
//for calculating an row 
int main(){
    int n; 
    cin>>n;

    int prev = 1;
    cout<<prev;
    for(int i=1; i<=n; i++){
        int cur = (prev * (n-i+1))/i;
        cout<<" "<<cur;
        prev = cur;
    }
    return 0;
}

