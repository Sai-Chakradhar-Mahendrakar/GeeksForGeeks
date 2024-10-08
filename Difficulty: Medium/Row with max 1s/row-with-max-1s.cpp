//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int> > &arr) {
        // code here
        int m=arr.size();
        int n=arr[0].size();
        int cnt=0;
        int idx=-1;
        for(int i=0;i<m;i++){
            auto it = lower_bound(arr[i].begin(), arr[i].end(), 1);
            int cnt_ = n - (it - arr[i].begin());
            if(cnt_>cnt){
                cnt=cnt_;
                idx=i;
            }
        }
        return idx;
    }
  private:
    int lowerBound(){
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > arr(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends