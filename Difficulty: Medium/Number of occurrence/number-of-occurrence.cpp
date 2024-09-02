//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    // code here
	    int lb=lowerBound(arr, n, x);
	    int ub=upperBound(arr, n, x);
	    
	    if(lb==n || arr[lb]!=x){
	        return 0;
	    }
	    
	    return ub-lb;
	}
private:
    int lowerBound(int arr[], int n, int x){
        int s=0;
        int e=n-1;
        int ans=n;
        
        while(s<=e){
            int mid=(s+e)/2;
            if(arr[mid]>=x){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
    int upperBound(int arr[], int n, int x){
        int s=0;
        int e=n-1;
        int ans=n;
        
        while(s<=e){
            int mid=(s+e)/2;
            if(arr[mid]>x){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends