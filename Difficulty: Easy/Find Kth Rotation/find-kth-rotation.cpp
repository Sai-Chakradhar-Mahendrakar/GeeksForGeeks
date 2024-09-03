//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int n=arr.size();
        int s=0;
        int e=n-1;
        
        while(s<=e){
            int mid=(s+e)/2;
            int next=(mid+1)%n;
            int prev=(mid+n-1)%n;
            
            if(arr[mid]<=arr[next] && arr[mid]<=arr[prev]){
                return mid;
            }
            else if(arr[mid]<=arr[e]){
                e=mid-1;
            }
            else if(arr[mid]>=arr[s]){
                s=mid+1;
            }
        }
        return 0;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        Solution ob;
        int res = ob.findKRotation(arr);
        cout << res << endl;
    }
}
// } Driver Code Ends