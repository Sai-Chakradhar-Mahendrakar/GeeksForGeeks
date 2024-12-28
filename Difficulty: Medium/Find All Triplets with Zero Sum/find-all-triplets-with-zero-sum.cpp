//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<vector<int>> findTriplets(vector<int> &arr) {
        // Code here
        int n=arr.size();
        vector<vector<int>> ans;
        unordered_map<int, vector<int>> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);
        }
        
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n;j++){
                int diff = -(arr[i]+arr[j]);
                if(mp.find(diff)!=mp.end()){
                    for(auto k : mp[diff]){
                        if(k>j){
                            ans.push_back({i, j, k});
                        }
                    }
                }
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;

        vector<vector<int>> res = ob.findTriplets(arr);
        sort(res.begin(), res.end());
        if (res.size() == 0) {
            cout << "[]\n";
        }
        for (int i = 0; i < res.size(); i++) {
            for (int j = 0; j < res[i].size(); j++) {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends