//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

#define MAXN 200000
vector<int> sie(MAXN+1, 1);

class Solution {
  public:
    void sieve() {
        sie[0]=0;
        for(int i=2;i<=MAXN;i++){
            if(sie[i]==1){
                for(int j=i;j<=MAXN;j+=i){
                    if(sie[j]==1){
                        sie[j]=i;
                    }
                }
            }
        }
    }

    vector<int> findPrimeFactors(int N) {

        // Write your code here
        vector<int> res;
        while(N!=1){
            res.push_back(sie[N]);
            N=N/sie[N];
        }
        
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        int n;
        cin >> n;

        Solution obj;
        obj.sieve();
        vector<int> vec = obj.findPrimeFactors(n);
        for (int i = 0; i < vec.size(); i++) {
            cout << vec[i] << " ";
        }
        cout << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends