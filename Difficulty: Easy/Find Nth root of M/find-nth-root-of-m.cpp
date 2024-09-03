//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define ll long long int
class Solution{
	public:
	int NthRoot(int n, int m){
	    // Code here.
	    int s=1;
	    int e=m;
	    while(s<=e){
	        int mid=(s+e)/2;
	        ll res = 1;
            bool overflow = false;

            for (int i = 0; i < n; i++) {
                res *= mid;
                if (res > m) {
                    overflow = true;
                    break;
                }
            }
	        
	        if(res==m){
	            return mid;
	        }
	        else if(overflow || res>m){
	            e=mid-1;
	        }
	        else{
	            s=mid+1;
	        }
	    }
	    return -1;
	} 
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends