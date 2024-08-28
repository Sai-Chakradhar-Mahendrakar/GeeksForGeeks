//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void print_divisors(int n) {
        // Code here.
        vector<int> res;
        for(int i=1;i<=sqrt(n);i++){
            if(n%i==0){
                if(n/i==i){
                    res.push_back(i);
                }
                else{
                    res.push_back(i);
                    res.push_back(n/i);
                }
            }
        }
        
        sort(res.begin(), res.end());
        for(auto x:res){
            cout<<x<<" ";
        }
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        Solution ob;
        ob.print_divisors(n);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends