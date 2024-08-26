//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
#define ll long long int

ll dist(string s){
    int n=s.size();
    vector<ll> dp(n+1,0);
    vector<ll> lC(256, -1);
    
    dp[0]=1;
    
    for(ll i=1;i<=n;i++){
        dp[i]=2*dp[i-1];
        
        char c=s[i-1];
        if(lC[c]!=-1){
            dp[i]-=dp[lC[c]];
        }
        
        lC[c]=i-1;
    }
    
    return dp[n];
}


class Solution {
  public:
    string betterString(string str1, string str2) {
        // code here
        ll cnt1 = dist(str1);
        ll cnt2 = dist(str2);
        
        if(cnt1>=cnt2){
            return str1;
        }
        else{
            return str2;
        }
     }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str1, str2;
        cin >> str1 >> str2;
        Solution obj;
        string ans = obj.betterString(str1, str2);
        cout << ans << "\n";
    }
}

// } Driver Code Ends