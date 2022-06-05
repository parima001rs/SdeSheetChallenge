#include<iostream>
using namespace std;

//using sorting TC:O(Nlog N + N) & SC:O(1)
void solveBrute(vector<int> &arr){
    sort(arr.start(), arr.end());
    for(int i=0; i<n; i++){
        if(arr[i] == arr[i+1]){
            return arr[i];
        }
    }
}

//using frequency array TC:O(N) & SC:O(N)
void solveBetter(vector<int> &arr){
    int freq[arr.size()+1] = {0};
    for(int i=0; i<n; i++){
        if(freq[arr[i]] == 0){
            freq[arr[i]] +=1;
        }
        else{
            return arr[i];
        }
    }
}

//Using LinkedList Cycle method TC:O(N) & SC:O(1)
void solveOptimal(vector<int> &arr){
    int slow = arr[0];
    int fast = arr[0];
    
    do{
        slow = arr[slow];
        fast = arr[arr[fast]];
    }while(slow != fast);

    fast = arr[0];
    while(slow != fast){
        slow = arr[slow];
        fast = arr[fast];
    }
    return slow;
}

int main(){
    vector<int> arr;
    arr = {1, 3, 4, 2, 3};
    int res = solveBrute(arr);
    int res = solveBetter(arr);
    int res = solveOptimal(arr);
    cout<<res;
    return 0;
}