#include <bits/stdc++.h>
using namespace std;

long long int max_Sum(long long int arr[], long long int n) {
    long long first = arr[0];
    long long second = 0;
    for (int i = 1; i < n; i++) {
        if (first < arr[i]) {
            second = first;
            first = arr[i];
        }
    }
    return first + second;
}

int main() {
    freopen("testcases_Q1.txt","r",stdin);
    freopen("output_Q1.txt","w",stdout);
    int t; cin >> t;
    while(t--){
    long long n;cin>>n;
    long long arr[n];
    for(int i=0;i<n;i++){
        
        cin>>arr[i];
    }
    long long int ans = max_Sum(arr, n);
    cout << ans;


    }
    return 0;
}
