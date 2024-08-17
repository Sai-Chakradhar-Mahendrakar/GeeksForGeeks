//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        // Complete the function
        unordered_map<int, int> prefixSumMap;
        int sum = 0;
        int maxLen = 0;
        
        for (int i = 0; i < N; i++) {
            sum += A[i];
            
            if (sum == K) {
                maxLen = i + 1;
            }
            
            if (prefixSumMap.find(sum - K) != prefixSumMap.end()) {
                maxLen = max(maxLen, i - prefixSumMap[sum - K]);
            }
            
            if (prefixSumMap.find(sum) == prefixSumMap.end()) {
                prefixSumMap[sum] = i;
            }
        }
        
        return maxLen;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends