//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution {
  public:
    int maxLen(vector<int>& arr, int n) {
        // Your code here
        unordered_map<int, int> mp;
        int cs=0;
        int mi=0;
        for(int i=0;i<n;i++){
            cs+=arr[i];
            if(cs==0){
                mi=i+1;
            }
            else{
                if(mp.find(cs)!=mp.end()){
                    mi = max(mi, i-mp[cs]);
                }
                else{
                    mp[cs]=i;
                }
            }
        }
        return mi;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int m;
        cin >> m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i) {
            cin >> array1[i];
        }
        Solution ob;
        cout << ob.maxLen(array1, m) << endl;
    }
    return 0;
}

// } Driver Code Ends