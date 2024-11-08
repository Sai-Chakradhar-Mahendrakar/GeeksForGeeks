//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& adj) {
        // Code here
        int V=adj.size();
        vector<bool> vis(V, false);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(adj, vis, i, -1)){
                    return true;
                }
            }
        }
        return false;
    }
  private:
    bool dfs(vector<vector<int>>& adj, vector<bool>& vis, int node, int parent){
        vis[node]=true;
        for(auto nbr: adj[node]){
            if(!vis[nbr]){
                if(dfs(adj, vis, nbr, node)){
                    return true;
                }
            }
            else if(nbr!=parent){
                return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends