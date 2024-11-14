//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution {
  public:
    int floorSqrt(int n) {
        // Your code goes here
        int s=1;
        int e=n;
        int ans=0;
        
        while(s<=e){
            int mid = (s+e)/2;
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
        int n;
        cin >> n;
        Solution obj;
        cout << obj.floorSqrt(n) << endl;
    }
    return 0;
}

// } Driver Code Ends