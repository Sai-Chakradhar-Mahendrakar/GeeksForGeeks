//{ Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
	public:
	vector<int>AllPrimeFactors(int N) {
	    // Code here
	    set<int> res;
	    while(N%2==0){
	       res.insert(2);
	       N/=2;
	    }
	    
	    for(int i=3;i<=sqrt(N);i+=2){
	        while(N%i==0){
	            res.insert(i);
	            N/=i;
	        }
	    }
	    
	    if(N>2){
	        res.insert(N);
	    }
	    
	    return vector<int>(res.begin(), res.end());
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		long long int N;
		cin >> N;
		Solution ob;
		vector<int>ans = ob.AllPrimeFactors(N);
		for(auto i: ans)
			cout << i <<" ";
		cout <<"\n";
	}  
	return 0;
}
// } Driver Code Ends