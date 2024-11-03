//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your code goes here
        int n=mat.size();
        vector<string> ans;
        string path;
        vector<vector<int>>vis(n, vector<int>(n, 0));
        solve(mat, ans, path, 0, 0, vis);
        return ans;
    }
  private:
    void solve(vector<vector<int>>& mat, vector<string>& ans, string& path, int r, int c, vector<vector<int>>& vis){
        int n=mat.size();
        // Base case
        if(r==n-1 && c==n-1 && mat[r][c]!=0){
            ans.push_back(path);
            return;
        }
        
        // check Boundary
        if (r<0 || r>=n || c<0 || c>=n || vis[r][c] || mat[r][c]==0) {
            return;
        }
        
        vis[r][c]=1;
        
        if(r+1<n && mat[r+1][c]!=0 && !vis[r+1][c]){
            path.push_back('D');
            solve(mat, ans, path, r+1, c, vis);
            path.pop_back();
        }
        
        if(c+1<n && mat[r][c+1]!=0 && !vis[r][c+1]){
            path.push_back('R');
            solve(mat, ans, path, r, c+1, vis);
            path.pop_back();
        }
        
        if(r-1>=0 && mat[r-1][c]!=0 && !vis[r-1][c]){
            path.push_back('U');
            solve(mat, ans, path, r-1, c, vis);
            path.pop_back();
        }
        
        if(c-1>=0 && mat[r][c-1]!=0 && !vis[r][c-1]){
            path.push_back('L');
            solve(mat, ans, path, r, c-1, vis);
            path.pop_back();
        }
        
        vis[r][c]=0;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends