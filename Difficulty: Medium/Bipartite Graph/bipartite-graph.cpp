//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> visited(V, 0); 
	    int color=1;
	    for (int i = 0; i < V; ++i) {
            if (visited[i] == 0) { // Check for disconnected components
                if (!dfs(adj, i, visited, 1)) {
                    return false;
                }
            }
        }
	    return true;
	}

private:
    bool dfs(vector<int> adj[], int node, vector<int>& visited, int color){
        visited[node] = color;
        
        for(auto nbr:adj[node]){
            if(visited[nbr]==0){
                int subpro = dfs(adj, nbr, visited, 3-color);
                if(subpro==false){
                    return false;
                }
            } else if(color==visited[nbr]){
                return false;
            }
        }
        
        return true;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends