//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long gcd(auto a, auto b){
        if(b==0){
            return a;
        }
        return gcd(b, a%b);
    }
    
    vector<long long> lcmAndGcd(long long A , long long B) {
        // code here
        vector<long long> res;
        
        if(A>B){
            swap(A, B);
        }
        
        auto g = gcd(A, B);
        auto l = (A*B)/g;
        
        res.push_back(l);
        res.push_back(g);
        
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long A,B;
        
        cin>>A>>B;

        Solution ob;
        vector<long long> ans = ob.lcmAndGcd(A,B);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}
// } Driver Code Ends