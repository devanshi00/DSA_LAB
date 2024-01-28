#include<bits/stdc++.h>
using namespace std;
#define int long long 
void Merge(int a[], int l, int m, int h) {
    int b[h + 1];
    int i = l;
    int k = l;
    int j = m + 1;
    while (i <= m && j <= h) {
        if (a[i] <= a[j]) {
            i++;
        } else {
            int temp;
            temp=a[j];
           
            int ptr=m;
            while(ptr>=i){
               
                a[ptr+1]=a[ptr];
                ptr--;
            }
            a[i]=temp;
            i++;
            m++;
            j++;

        }
    }

}


signed main(){
    freopen("test_cases_Q2.txt","r",stdin);
    freopen("output_Q2.txt","w",stdout);
    int t;
    cin >> t;

    while(t--){
        int N1;
        cin >> N1;
       
        int *a = new int[N1];
       
        for(int i = 0; i<N1; i++){
            cin >> a[i];
        }
        
    Merge(a,0,50000,N1-1);

    for(int i=0;i<N1;i++){
        cout<<a[i]<<" ";
    }
    
    cout<<endl;
        

}
    
    // int arr[]={1,10,51,7,7};
    // Merge(arr,0,2,4);
    // for(int i=0;i<5;i++){
    //     cout<<arr[i]<<" ";
    // }
}