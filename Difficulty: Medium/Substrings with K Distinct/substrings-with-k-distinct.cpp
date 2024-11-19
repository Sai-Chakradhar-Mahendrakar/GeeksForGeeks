//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int substrCount(string str, int k) {
        // code here.
        return longCnt(str, k) - longCnt(str, k-1);
    }
  private:
    long longCnt(string str, int k){
        int i=0;
        int j=0;
        int n=str.size();
        unordered_map<char, int> mp;
        int ans=0;
        int distinctChar=0;
        while(j<n){
            char ch=str[j];
            mp[ch]++;
            if(mp[ch]==1){
                distinctChar++;
            }
            
            while(distinctChar>k){
                mp[str[i]]--;
                if(mp[str[i]]==0){
                    distinctChar--;
                }
                i++;
            }
            j++;
            ans+=(j-i+1);
        }
        return ans;
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
        cout << ob.substrCount(s, k) << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends