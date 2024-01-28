#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

int findMedian(vector<int>& vec) {
    sort(vec.begin(), vec.end());
    return vec[vec.size() / 2];
}

int medianOfMedians(vector<int>& arr, int left, int right) {
    if (right - left < 5) {
        vector<int> temp(arr.begin() + left, arr.begin() + right + 1);
        return findMedian(temp);
    }

    vector<int> medians;
    for (int i = left; i <= right; i += 5) {
        int subRight = min(i + 4, right);
        vector<int> temp(arr.begin() + i, arr.begin() + subRight + 1);
        medians.push_back(findMedian(temp));
    }
    return medianOfMedians(medians, 0, medians.size() - 1);
}

int partition(vector<int>& arr, int left, int right, int pivot) {
    int pivotIndex = left;
    for (int i = left; i <= right; i++) {
        if (arr[i] == pivot) {
            pivotIndex = i;
            break;
        }
    }
    swap(arr[pivotIndex], arr[right]);
    pivotIndex = left;
    for (int i = left; i < right; i++) {
        if (arr[i] <= pivot) {
            swap(arr[i], arr[pivotIndex]);
            pivotIndex++;
        }
    }
    swap(arr[pivotIndex], arr[right]);
    return pivotIndex;
}

void quickSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int pivot = medianOfMedians(arr, left, right);
        int partitionIndex = partition(arr, left, right, pivot);
        quickSort(arr, left, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, right);
    }
}

signed main() {
    freopen("test_cases_Q6.txt","r",stdin);
    freopen("output_Q6.txt","w",stdout);
    int t;
    cin >> t;

    while (t--) {
        int N1;
        cin >> N1;

        vector<int> vec(N1);
        for (int i = 0; i < N1; i++) {
            cin >> vec[i];
        }
        quickSort(vec, 0, N1 - 1);
        cout << "Sorted array: " << endl;
        for (int i = 0; i < N1; i++) {
            cout << vec[i] << " ";
        }
        cout << endl; 
}
