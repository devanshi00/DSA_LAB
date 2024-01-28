#include<bits/stdc++.h>
using namespace std;

int main(){
   
   
    // int arr[]={1,4,6,8,43,2,64,-1,64,-3,6};
    // int n=sizeof(arr)/sizeof(arr[0]);
  
     
    // long long first = arr[0];
    // long long second = INT_MAX;
    // for (int i = 1; i < n; i++) {
    //     if (first > arr[i]) {
    //         second = first;
    //         first = arr[i];
    //     }
    // }
    // cout<<first<<" "<<second;
    freopen("test_cases_Q5.txt","r",stdin);
    freopen("output_Q5.txt","w",stdout);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        long long mx1 = LLONG_MAX, mx2 = LLONG_MAX;
        for(int i=0; i<n; i++){
            long long t; cin >> t;
            if(t < mx1){
                mx2 = mx1;
                mx1 = t;
            }
        }
        cout<<mx1<<" "<<mx2<<endl;


       

    }
}