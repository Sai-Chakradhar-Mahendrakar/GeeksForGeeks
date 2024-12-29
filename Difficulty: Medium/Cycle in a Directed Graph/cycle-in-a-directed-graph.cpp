//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<vector<int>> adj) {
        // code here
        vector<bool> vis(V, false);
        vector<bool> stack(V, false);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(adj, i, vis, stack)){
                    return true;
                }
            }
        }
        return false;
    }
  private:
    bool dfs(vector<vector<int>>& adj, int node, vector<bool>& vis, vector<bool>& stack){
        vis[node]=true;
        stack[node]=true;
        for(auto nbr: adj[node]){
            if(stack[nbr]==true){
                return true;
            }
            else if(!vis[nbr]){
                if(dfs(adj, nbr, vis, stack)){
                    return true;
                }
            }
        }
        stack[node]=false;
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends