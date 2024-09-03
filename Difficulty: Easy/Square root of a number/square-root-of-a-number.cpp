//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to find square root
// x: element to find square root
#define ll long long int
class Solution {
  public:
    long long int floorSqrt(long long int n) {
        // Your code goes here
        // if(n<=1){
        //     return n;
        // }
        ll s=1;
        ll e=n;
        ll ans=0;
        while(s<=e){
            ll mid=(s+e)/2;
            if(mid*mid==n){
                return mid;
            }
            else if(mid*mid<n){
                ans=mid;
                s=mid+1;
            }
            else{
                e=mid-1;
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
        long long n;
        cin >> n;
        Solution obj;
        cout << obj.floorSqrt(n) << endl;
    }
    return 0;
}

// } Driver Code Ends