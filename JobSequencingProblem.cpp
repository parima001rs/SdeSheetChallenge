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
pair<int, int> JobScheduling(Job arr[], int n){
    //sort acc. to profit
    sort(arr, arr+n, comp);

    //find maximum deadline
    int maxi = arr[0].dead;
    for(int i = 1; i<n; i++){
        maxi = max(maxi, arr[i].dead);
    }

    //make slot arr
    int slot[maxi] = -1;
    for(int i=0; i<=maxi; i++){
        slot[i] = -1;
    }

    //main kaam
    int countJobs = 0, jobProfit = 0;
    for(int i=0; i<n; i++){ //job id
        for(int j=arr[i].dead; j>0; j--){
            if(slot[j] == -1){ //whichever day is empty
                slot[j] = i;
                countJobs++;
                jobProfit += arr[i].profit;
                break;
            }
        }
    }
    return make_pair(countJobs, jobProfit);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        Job arr[n];
        for(int i=0; i<n; i++){
            int x, y, z;
            cin>>x, y, z;
            arr[i].id = x;
            arr[i].dead = y;
            arr[i].profit = z;
        }
        vector<int>ans = JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }

    return 0;
}

// SDE Sheet – 180 Questions and many concepts and algo
// InterviewBit – Amazon Oriented – 205 questions
// Top interview questions leetcode - 71
// +114 = 500
// stl in one video
// Core subjects: OS, DBMS, OOPS, CN
// Amazon Archives
// Aptitude
// LeaderShip Principles
// mock interviews

//July - Sde sheet
//August - interview bit
//September - interview bit + leetcode
//October - archives

