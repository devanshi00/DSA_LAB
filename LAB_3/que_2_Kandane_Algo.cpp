#include<bits/stdc++.h>
using namespace std;
#define int long long
int vec[1000000];
int LRSA(int v[],int l,int h) {
    int sum=INT_MIN;
    int curr_sum=0;
    for(int i=l;i<h+1;i++){
        curr_sum+=v[i];
         if(curr_sum>sum){
            sum=curr_sum;
         }
         if(curr_sum<0){
            curr_sum=0;
         }
       

    }
    return sum;
}

signed main(){
    freopen("test_cases_Q1.txt","r",stdin);
    freopen("output_Q2_f_large.txt","w",stdout);
    int t;
    cin >> t;

    while (t--) {
        int N1;
        cin >> N1;

        
        for (int i = 0; i < N1; i++) {
            cin >> vec[i];
        }
        int a =LRSA(vec,0,N1-1);
        cout<<a<<endl;
    }
return 0;
}