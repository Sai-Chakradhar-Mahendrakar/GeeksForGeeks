//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void convertMinToMaxHeap(vector<int> &arr, int N){
        for(int i=(N-2)/2;i>=0;i--){
            MaxHeapify(arr,i,N);
        }
    }
private:
    void MaxHeapify(vector<int> &arr, int i, int N){
        int l=2*i+1;
        int r=2*i+2;
        int largest=i;
        
        if(l<N && arr[l]>arr[i]){
            largest=l;
        }
        if(r<N && arr[r]>arr[largest]){
            largest=r;
        }
        if(largest!=i){
            swap(arr[i], arr[largest]);
            MaxHeapify(arr, largest, N);
        }
    }
    
};


//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> vec(n);
       for(int i = 0;i<n;i++) cin >> vec[i];

        Solution obj;
        obj.convertMinToMaxHeap(vec,n);
        for(int i = 0;i<n;i++) cout << vec[i] << " ";
        cout << endl;
        

        
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends