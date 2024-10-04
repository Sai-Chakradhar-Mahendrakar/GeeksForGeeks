//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<vector<int>> CombinationSum2(vector<int> arr,int n,int k){
        //code here
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        vector<int> cur;
        helper(0, k, arr, ans, cur);
        return ans;
    }
private:
    void helper(int idx, int target, vector<int>& arr, vector<vector<int>>& ans, vector<int>& cur){
        if(target==0){
            ans.push_back(cur);
            return;
        }
        
        for(int i=idx;i<arr.size();i++){
            if(i>idx && arr[i]==arr[i-1]){
                continue;
            }
            if(arr[i]>target){
                break;
            }
            cur.push_back(arr[i]);
            helper(i+1, target-arr[i], arr, ans, cur);
            cur.pop_back();
        }
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        auto obj=ob.CombinationSum2(arr,n,k);
        for(int i=0;i<obj.size();i++)
        {
            for(int j=0;j<obj[i].size();j++)
            {
                cout<<obj[i][j]<<" ";
            }
            cout<<"\n";
        }
        if(obj.size()==0) cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends