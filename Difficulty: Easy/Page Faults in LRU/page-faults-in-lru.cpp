//{ Driver Code Starts
// Initial Template for C++



#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int pageFaults(int N, int C, int pages[]){
        // code here
        vector<int>v;
        int fault=0;
        int i=0;
        while(i<N){
            if(find(v.begin(),v.end(),pages[i])==v.end()){
                   if(v.size()>=C){
                       v.erase(v.begin());
                   }
                    v.push_back(pages[i]);
                    fault++;
            }else{
                auto it=find(v.begin(),v.end(),pages[i]);
                v.erase(it);
                v.push_back(pages[i]);
            }
            i++;
        }
        return fault;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, C;
        cin>>N;
        int pages[N];
        for(int i = 0;i < N;i++)
            cin>>pages[i];
        cin>>C;
        
        Solution ob;
        cout<<ob.pageFaults(N, C, pages)<<"\n";
    }
    return 0;
}
// } Driver Code Ends