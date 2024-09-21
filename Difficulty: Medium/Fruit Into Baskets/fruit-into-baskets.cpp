//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int totalFruits(vector<int> &arr) {
        int l=0;
        int r=0;
        int n=arr.size();
        int maxWin=0;
        
        unordered_map<int, int> mp;
        
        while(r<n){
            mp[arr[r]]++;
            
            if(mp.size()>2){
                if(--mp[arr[l]]==0){
                    mp.erase(arr[l]);
                }
                l++;
            }
            maxWin=max(maxWin, r-l+1);
            r++;
        }
        return maxWin;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore any newline character left in the buffer
    while (t--) {
        string line;
        getline(cin, line); // Read the entire line of input
        stringstream ss(line);
        vector<int> arr;
        int num;

        // Parse the input line into integers and add to the vector
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        int ans = ob.totalFruits(arr);

        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends