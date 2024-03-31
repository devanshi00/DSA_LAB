#include <bits/stdc++.h>
using namespace std;
 
struct Job {
   
    char id; // Job Id
    int dead; // Deadline of job
    int profit; // Profit earned if job is completed before
};
bool comparison(Job a,Job b){
    return (a.profit>b.profit);
}

void JobScheduling(Job arr[],int n){
    sort(arr,arr+n,comparison);
    int maxi=arr[0].dead;
    for(int i=1;i<n;i++){
        maxi=max(maxi,arr[i].dead);

    }
    char slot[maxi+1];
    for(int i=0;i<=maxi;i++){
        slot[i]='*';
    }
    int jobProfit=0;
    for(int i=0;i<n;i++){
        for(int j=arr[i].dead;j>0;j--){
            if(slot[j]=='*'){
                slot[j]=arr[i].id;
                jobProfit+=arr[i].profit;
                break;
            }
        }
    }
    for(int k=0;k<maxi+1;k++){
        if(slot[k]!='*'){
            cout<<slot[k]<<" ";

        }
    }
    cout<<endl;
    cout<<"PROFIT "<<jobProfit;


}

int main(){
    Job arr[]= { { 'a', 2, 100 },
                  { 'b', 1, 19 },
                  { 'c', 2, 27 },
                  { 'd', 1, 25 },
                  { 'e', 3, 15 } };
   
    int n = sizeof(arr) / sizeof(arr[0]);
    JobScheduling(arr,n);
}