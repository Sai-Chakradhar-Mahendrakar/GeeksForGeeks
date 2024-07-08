//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    
    int numberOfWays(int n) {
        if (n == 0) return 1;  // 1 way to tile an empty board
        if (n == 1) return 1;  // 1 way to tile a 2x1 board with a single 1x2 domino

        int mod = 1e9 + 7;
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; ++i) {
            dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
        }

        return dp[n];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;

        Solution ob;
        cout << ob.numberOfWays(n) << endl;
    }
    return 0;
}
// } Driver Code Ends