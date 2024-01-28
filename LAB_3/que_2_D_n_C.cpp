#include <bits/stdc++.h> 
using namespace std; 

#define int long long
int a[1000000];

int maxCrossingSum(int arr[], int l, int m, int h) { 
 
	int sum = 0; 
	int left_sum = INT_MIN; 
	for (int i = m; i >= l; i--) { 
		sum = sum + arr[i]; 
		if (sum > left_sum) 
			left_sum = sum; 
	} 

	sum = 0; 
	int right_sum = INT_MIN; 
	for (int i = m+1; i <= h; i++) { 
		sum = sum + arr[i]; 
		if (sum > right_sum) 
			right_sum = sum; 
	} 

	
	return (left_sum+ right_sum); 
} 
int maxSubArraySum(int arr[], int l, int h) { 


	if (l == h) 
		return arr[l]; 

	int m = (l + h) / 2; 

    int left=maxSubArraySum(arr, l, m);
    int right=maxSubArraySum(arr, m + 1, h);
    int cross=maxCrossingSum(arr, l, m, h);
	return max({left,right,cross}); 
} 
signed main() { 
freopen("test_cases_Q1.txt","r",stdin);
    freopen("output_Q2_arr.txt","w",stdout);
    int t;
    cin >> t;

    while (t--) {
        int N1;
        cin >> N1;

    
        for (int i = 0; i < N1; i++) {
            cin >> a[i];
        }
        int b=maxSubArraySum(a,0,N1-1);
        cout<<"MAX_SUM "<<b<<endl;
       
    }
        
	return 0; 
} 
