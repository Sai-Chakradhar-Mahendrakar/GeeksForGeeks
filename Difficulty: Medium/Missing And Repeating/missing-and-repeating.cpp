//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        
        long long l = arr.size();
        
        long long repeatingNumber = 0;
        long long missingNumber = 0;
    
        // Sum of first n natural numbers
        long long sn = (l * (l + 1)) / 2;
        // Sum of squares of first n natural numbers
        long long sn2 = (l * (l + 1) * (2 * l + 1)) / 6;
        
        long long s = 0;
        long long s2 = 0;
    
        // Calculate sum and sum of squares from the array
        for (int i = 0; i < n; i++) {
            s += arr[i];
            s2 += (long long)arr[i] * (long long)arr[i];
        }
    
        // X = repeating number, Y = missing number
        long long xY = (s2 - sn2) / (s - sn); // x + Y
        long long Xy = s - sn; // X - y
    
        repeatingNumber = (xY + Xy) / 2;
        missingNumber = repeatingNumber - Xy;
        
        return {(int)repeatingNumber, (int)missingNumber};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends