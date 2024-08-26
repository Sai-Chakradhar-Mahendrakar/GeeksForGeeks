//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void bitManipulation(int num, int i) {
        // your code here
        
        // Get Bit
        cout<<get(num, i)<<" ";
        
        // Set Bit
        cout<<set(num, i)<<" ";
        
        // Clear Bit
        cout<<clear(num, i)<<" ";
    }
  private:
    int get(int num, int i){
        int mask=1<<(i-1);
        return num&mask ? 1:0;
    }
    
    int set(int num, int i){
        int mask=1<<(i-1);
        return num|mask;
    }
    
    int clear(int num, int i){
        int mask=~(1<<(i-1));
        return num&mask;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n >> i;
        Solution ob;
        ob.bitManipulation(n, i);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends