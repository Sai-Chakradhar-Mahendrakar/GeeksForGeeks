//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        // code here
        int xorNum=0;
        for (int i = 0; i < N; i++) {
            xorNum ^= Arr[i];
        }
        
        int pos=0;
        int temp=xorNum;
        while((temp&1)==0){
            pos++;
            temp=temp>>1;
        }
        
        int mask=(1<<pos);
        
        int setA=0;
        int setB=0;
        for (int i = 0; i < N; i++) {
            if ((Arr[i] & mask) > 0) {
                setA ^= Arr[i];
            } else {
                setB ^= Arr[i];
            }
        }
        
        vector<long long int> result;
        if(setA<setB){
            result.push_back(setB);
            result.push_back(setA);
        }else{
            result.push_back(setA);
            result.push_back(setB);
        }
    
        return result;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends