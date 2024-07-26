//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    int n = A.size();
		    
		    unordered_map<char, int> m;
		    queue<char>q;
		    
		    string res;
		    
		    for(int i=0;i<n;i++){
		        if(m.find(A[i])==m.end()){
		            q.push(A[i]);
		        }
		        
		        m[A[i]]++;
		        
		        while(!q.empty() && m[q.front()]>1){
		            q.pop();
		        }
		        
		        if(!q.empty()){
		            res+=q.front();
		        }
		        else{
		            res+='#';
		        }
		    }
		   return res; 
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends