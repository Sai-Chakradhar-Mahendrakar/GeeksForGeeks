//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int setBit(int n) {
        // Write Your Code here
        if(n==-1){
            return n;
        }
        
        return n|(~n&(n+1));
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        int ans = ob.setBit(N);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends