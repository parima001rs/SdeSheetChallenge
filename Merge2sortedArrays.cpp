#include<bits/stdc++.h>
using namespace std;

// Input: 
// n = 4, arr1[] = [1 4 8 10] 
// m = 5, arr2[] = [2 3 9]

// Output: 
// arr1[] = [1 2 3 4]
// arr2[] = [8 9 10]

//Brute force 
void solveBrute(vector<int> &a, vector<int> &b){
    int n1 = a.size(), n2 = b.size(), n = n1+n2;
    vector<int>res(n);
    for(int i=0; i<n1; i++)
        res.push_back(a[i]);
    for(int i=0; i<n2; i++)
        res.push_back(b[i]);

    sort(res.begin(), res.end());
    a.clear(); b.clear();
    for(int i=0; i<n1; i++)
        a.push_back(res[i]);
    for(int i=n1; i<n2; i++)
        b.push_back(res[i]);
}

//Better Approach: TC: O(n1 * n2) n1~ linear traversal, n2~ reordering & SC:O(1)
void solveBetter(vector<int> &a, vector<int> &b){
    int i=0, j=0;
    while(i<a.size() && j<b.size()){
        if(a[i] > b[j]){
            swap(a[i], b[j]);
            sort(b.begin(), b.end()); // reordering
            i++;
        }
        else{
            i++;
        }
    }
    sort(b.begin(), b.end());
}

//avoiding sorting 
void solveBetter2(vector<int> &a, vector<int> &b){
    int i, k;
    for(i=0; i<a.size(); i++){
        if(a[i] > b[0]){
            swap(a[i], b[0]);
        }
        int first = b[0];
        //insertion sort
        for(k=1; k<b.size() && b[k] < first; k++){
            b[k-1] = b[k];
        }
        b[k-1] = first;
    }
}


//Optimal: Gap Algorithm TC:O() & SC:O()
void solveOptimal(vector<int> &a, vector<int> &b){
    int n = a.size(), m = b.size();
    int gap = ceil((float)((n + m)/2));

    while(gap >= 0){
        int i=0, j = gap;
        while(j< (n + m)){
            if(j< n && a[i] > b[j])
                swap(a[i], b[j]);
            else if(j >= n && i < n && a[i] > b[j-n])
                swap(a[i], b[j-n]);
            else if(j >= n && i >= n && a[i-n] > b[j-n])
                swap(a[i-n], b[j-n]);
            i++;
            j++;
        }

        if(gap == 1) gap = 0;
        else gap = ceil((float) gap/2);
    }
}

int main(){
    vector<int> a = {1, 4, 7, 8, 10}, b = {2, 3, 9};
    // solveBrute(a, b);
    // solveBetter(a, b);
    solveOptimal(a, b);
    for(auto &it: a)
        cout<<it;
    cout<<endl;
    for(auto &it: b)
        cout<<it;
    return 0;
}