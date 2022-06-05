#include<bits/stdc++.h>
using namespace std;

//Brute force
void sortColorsBrute(vector<int> &v){
    int count0 = 0, count1 = 0, count2 = 0;
    for(auto &it: v){
        if(it == 0) count0++;
        else if(it == 1) count1++;
        else count2++;
    }

    v.clear();
    while(count0){
        v.push_back(0);
    }
    while(count1){
        v.push_back(1);
    }
    while(count2){
        v.push_back(2);
    }
}

//Dutch National Flag Algorithm TC:O(N) & SC:O(1)
void sortColors(vector<int> &v){
    int n = v.size();
    int left = 0, mid = 0, right = n-1;

    while(mid <= right){
        switch(v[mid]){
            case 0:
                swap(v[left++], v[mid++]);
                break;
            case 1:
                mid++; break;
            case 2:
                swap(v[mid], v[right--]);
                break;
        }
    }
}

int main(){
    vector<int> v = {2, 0, 2, 1, 1, 0};
    sortColorsBrute(v);
    // sortColors(v);
    for(auto &it: v){
        cout<<it<<" ";
    }
    return 0;
}