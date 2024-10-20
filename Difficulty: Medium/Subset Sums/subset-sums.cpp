//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> subsetSums(vector<int> arr, int n) {
        // Write Your Code here
        vector<int> sum;
        helper(arr, sum, 0, 0);
        return sum;
    }
  private:
    void helper(vector<int>& arr, vector<int>& sum, int cur, int idx){
        if(idx==arr.size()){
            sum.push_back(cur);
            return;
        }
        
        // include
        helper(arr, sum, cur+arr[idx], idx+1);
        
        //exclude
        helper(arr, sum, cur, idx+1);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr, N);
        sort(ans.begin(), ans.end());
        for (auto sum : ans) {
            cout << sum << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends