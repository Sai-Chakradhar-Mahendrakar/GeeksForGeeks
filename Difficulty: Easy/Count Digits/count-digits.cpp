//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int evenlyDivides(int N){
        //code here
        int temp=N;
        int cnt=0;
        
        while(temp>0){
            int checkNo = temp%10;
            temp = temp/10;
            // cout<<checkNo<<" "<<temp<<endl;
            if(checkNo!=0 and N%checkNo==0){
                cnt++;
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.evenlyDivides(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends