//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    bool isPossible(int a,int b)
    {
        //code here
        if((a==2 || b==2) &&a!=b) return 1;
        else return 0;
    }
};
// for unique binary tree we should have inorder and 
// one among post or pre order
// so either one of a or b shd be inorder (a==2 || b==2) 
// && other should be other than inorder a!=b 

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b; 
        cin>>a>>b;
        Solution obj;
        bool ans=obj.isPossible(a,b);
        cout<<ans<<"\n";
    }
}
// } Driver Code Ends