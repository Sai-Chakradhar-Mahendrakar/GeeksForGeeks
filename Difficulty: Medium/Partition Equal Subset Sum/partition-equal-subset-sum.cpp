//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    
    vector<vector<int>> memo;

    int dp(int i, int sum, int nums[],int n){
        if(sum==0) return 1;
        if(i==n) return 0;

        if(memo[i][sum]!=-1){
            return memo[i][sum];
        }

        int ans = 0;
        
        if(sum>=nums[i]){
            ans |= dp(i+1, sum-nums[i], nums, n);
        }
        ans |= dp(i+1, sum, nums, n);

        return memo[i][sum] = ans;
    }

    int equalPartition(int n, int nums[]) {
        
        int sum = accumulate(nums, nums+n, 0);
        if(sum%2){
            return 0;
        }
        memo.resize(n+1, vector<int>(sum,-1));
        return dp(0, sum/2, nums, n);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends