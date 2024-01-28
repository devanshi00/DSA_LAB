#include<bits/stdc++.h>
using namespace std;
#define int long long 
void Merge(int a[], int l, int m, int h) {

    int i = l;
   
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
void InplaceMergeSort(int a[],int l,int h){
    
    if(l<h){
        int m=l+ (h-l)/2;
        InplaceMergeSort(a,l,m);
        InplaceMergeSort(a,m+1,h);
        Merge(a,l,m,h);

    }


}

signed main(){
    freopen("test_cases_Q3.txt","r",stdin);
    freopen("output_Q3.txt","w",stdout);
    int t;
    cin >> t;

    while(t--){
        int N1;
        cin >> N1;
       
        int *a = new int[N1];
       
        for(int i = 0; i<N1; i++){
            cin >> a[i];
        }
        
    InplaceMergeSort(a,0,N1-1);

    for(int i=0;i<N1;i++){
        cout<<a[i]<<" ";
    }
    
    cout<<endl;
        

}
}