#include<bits/stdc++.h>
using namespace std;

struct Job{
    int id;
    int dead;
    int profit;
};

bool comp(Job a, Job b){
    return a.profit > b.profit;
}

//TC:O(NlogN) + O(N*M) & SC:O(M)
vector<int> JobScheduling(Job arr[], int n){
    //sort acc. to profit
    sort(arr, arr+n, comp);

    //find maximum deadline
    int maxi = arr[0].dead;
    for(int i = 1; i<n; i++){
        maxi = max(maxi, arr[i].dead);
    }

    //make slot arr
    int slot[maxi];
    for(int i=0; i<=maxi; i++){
        slot[i] = -1;
    }

    //main kaam
    int countJobs = 0, jobProfit = 0;
    for(int i=0; i<n; i++){ //job id
        for(int j=arr[i].dead; j>0; j--){ //traversing slot from back
            if(slot[j] == -1){ //whichever day is empty
                slot[j] = i;
                countJobs++;
                jobProfit += arr[i].profit;
                break;
            }
        }
    }
    vector<int>res = {countJobs, jobProfit};
    return res;
}

int main(){
    int n = 4;
    Job arr[n] = {{1,4,20}, {2, 1, 10}, {3, 2, 40}, {4, 2, 30}};
    vector<int>ans = JobScheduling(arr, n);
    cout<<ans[0]<<" "<<ans[1]<<endl;
    

    return 0;
}

