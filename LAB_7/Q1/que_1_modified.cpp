#include<bits/stdc++.h>
using namespace std;

long long Knapsack (vector<long long>& val, vector<long long>& wt, int W, int n) {
    vector<long long> dp(W+1, 0);
    for(int i=1; i<=n; i++){
        for(int w=W; w>=0; w--){
            if(wt[i-1]<=w){
                dp[w]=max(dp[w], dp[w-wt[i-1]]+val[i-1]);
            }
        }
    }
    return dp[W];
}

int main(){

    freopen("testcases_Q2.txt","r",stdin);
    freopen("output_Q2.txt","w",stdout);
    int t; cin >> t;
    while(t--){

    int n, W; cin >> n >> W;
        vector<long long> weights(n), values(n);
        for(int i=0; i<n; i++)
            cin >> weights[i];
        for(int i=0; i<n; i++)
            cin >> values[i];
    int ans = Knapsack(values, weights, W, n);
    cout << ans<< endl;

    
}
return 0;
}
