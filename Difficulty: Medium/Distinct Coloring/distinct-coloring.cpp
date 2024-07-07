//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    long long int distinctColoring(int N, int r[], int g[], int b[]){
        // code here 
        vector<vector<long long int>> dp(N, vector<long long int>(3, 0));
        
        // Base Case
        dp[0][0] = r[0];
        dp[0][1] = g[0];
        dp[0][2] = b[0];
        
        for(int j=1; j<N; j++){
            dp[j][0] = min(dp[j-1][1], dp[j-1][2]) + r[j];
            dp[j][1] = min(dp[j-1][0], dp[j-1][2]) + g[j];
            dp[j][2] = min(dp[j-1][0], dp[j-1][1]) + b[j];
        }
        
        return min({dp[N-1][0], dp[N-1][1], dp[N-1][2]});
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int r[N],g[N],b[N];
        for(int i = 0; i < N; i++)
            cin >> r[i];
        for(int i = 0; i < N; i++)
            cin >> g[i];
        for(int i = 0; i < N; i++)
            cin >> b[i];
        
        Solution ob;
        cout << ob.distinctColoring(N, r, g, b) << endl;
    }
    return 0; 
}
// } Driver Code Ends