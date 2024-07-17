//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class DSU{
    vector<int> parent;
    vector<int> rank;
    
    public:
    
    DSU(int n){
        parent = vector<int>(n,-1);
        rank = vector<int>(n,1);
    }
    
    int find(int i){
        if(parent[i]==-1){
            return i;
        }
        return parent[i]=find(parent[i]);
    }
    
    void unionSet(int x, int y){
        int xroot = find(x);
        int yroot = find(y);
        
        if(xroot!=yroot){
            if(rank[xroot]<rank[yroot]){
                parent[xroot]=yroot;
                rank[yroot]+=xroot;
            }else{
                parent[yroot]=xroot;
                rank[xroot]+=yroot;
            }
        }
    }
};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        vector<vector<int>> edgeList;
    
        for (int i = 0; i < V; i++) {
            for (auto x : adj[i]) {
                int u = i;
                int v = x[0];
                int wt = x[1];
                edgeList.push_back({wt, u, v});
            }
        }
        
        sort(edgeList.begin(), edgeList.end());
        
        int ans = 0;
        DSU s(V);
        
        for (auto edge : edgeList) {
            int w = edge[0];
            int x = edge[1];
            int y = edge[2];
            
            if (s.find(x) != s.find(y)) {
                s.unionSet(x, y);
                ans += w;
            }
        }
        
        return ans;

    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends