//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long int inversionCount(long long arr[], int n) {
        long long temp[n]; // Temporary array for merging
        return mergeSort(arr, temp, 0, n - 1);
    }
    
private:
    long long int merge(long long arr[], long long temp[], int low, int mid, int high) {
        int i = low; // Starting index for left subarray
        int j = mid + 1; // Starting index for right subarray
        int k = low; // Starting index to be sorted
        long long int cnt = 0;
        
        while (i <= mid && j <= high) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
                cnt += (mid - i + 1); // Count inversions
            }
        }
        
        // Copy the remaining elements of left subarray, if any
        while (i <= mid) {
            temp[k++] = arr[i++];
        }
        
        // Copy the remaining elements of right subarray, if any
        while (j <= high) {
            temp[k++] = arr[j++];
        }
        
        // Copy the sorted subarray into Original array
        for (i = low; i <= high; i++) {
            arr[i] = temp[i];
        }
        
        return cnt;
    }
  
    long long int mergeSort(long long arr[], long long temp[], int low, int high) {
        long long int cnt = 0;
        if (low < high) {
            int mid = low + (high - low) / 2;
            cnt += mergeSort(arr, temp, low, mid);
            cnt += mergeSort(arr, temp, mid + 1, high);
            cnt += merge(arr, temp, low, mid, high);
        }
        return cnt;
    }  
};

//{ Driver Code Starts.

int main() {

    long long T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        long long A[N];
        for (long long i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A, N) << endl;
    }

    return 0;
}

// } Driver Code Ends