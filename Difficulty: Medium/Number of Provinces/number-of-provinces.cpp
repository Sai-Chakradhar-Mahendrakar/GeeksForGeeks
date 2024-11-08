//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<bool> vis(V, false);
        int res=0;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(adj, vis, i, V);
                res++;
            }
        }
        return res;
    }
  private:
    void dfs(vector<vector<int>>& adj, vector<bool>& vis, int i, int v){
        vis[i]=true;
        for(int j=0;j<v;j++){
            if(adj[i][j]==1 && !vis[j]){
                dfs(adj, vis, j, v);
            }
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends