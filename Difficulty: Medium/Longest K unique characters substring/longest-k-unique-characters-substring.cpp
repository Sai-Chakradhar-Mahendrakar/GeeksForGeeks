//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
        int l=0;
        int r=0;
        int winSize=-1;
        unordered_map<char, int> mp;
        int n=s.size();
        while(r<n){
            mp[s[r]]++;
            while(mp.size()>k){
                if(--mp[s[l]]==0){
                    mp.erase(s[l]);
                }
                l++;
            }
            if (mp.size()==k) {
                winSize = max(winSize, r-l+1);
            }
            r++;
        }
        return winSize;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends