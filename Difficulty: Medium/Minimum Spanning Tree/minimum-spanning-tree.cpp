//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        vector<pair<int, int>> l[V];

        for (int i = 0; i < V; i++) {
            for (auto &x : adj[i]) {
                int u = i;
                int v = x[0];
                int wt = x[1];
                l[u].push_back({v, wt});
                l[v].push_back({u, wt});
            }
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

        vector<bool> visited(V, false);
        int ans = 0;
        q.push({0, 0}); // wt, node

        while (!q.empty()) {
            auto best = q.top();
            q.pop();

            int to = best.second;
            int wt = best.first;

            if (visited[to]) {
                continue;
            }

            ans += wt;
            visited[to] = true;

            for (auto &x : l[to]) {
                if (!visited[x.first]) {
                    q.push({x.second, x.first});
                }
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