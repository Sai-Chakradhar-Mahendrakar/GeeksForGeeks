//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User code template

class Solution {
  public:
    vector<int> getFloorAndCeil(int x, vector<int> &arr) {
        // code here
         sort(arr.begin(), arr.end());
        int lb=floor(arr, x);
        int ub=ceil(arr, x);
        return vector<int>({lb, ub});
    }
  private:
    int floor(vector<int>& arr, int x){
        int s=0;
        int e=arr.size()-1;
        int ans=-1;
        
        while(s<=e){
            int mid=(s+e)/2;
            if(arr[mid]==x){
                return arr[mid];
            }
            else if(arr[mid]<x){
                ans=mid;
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return ans!=-1?arr[ans]:-1;
    }
    int ceil(vector<int>& arr, int x){
        int s=0;
        int e=arr.size()-1;
        int ans=-1;
        
        while(s<=e){
            int mid=(s+e)/2;
            if(arr[mid]==x){
                return arr[mid];
            }
            else if(arr[mid]>x){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans!=-1?arr[ans]:-1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t
    while (t--) {
        vector<int> arr;
        int x;
        string input;
        cin >> x;
        cin.ignore();

        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        auto ans = ob.getFloorAndCeil(x, arr);
        cout << ans[0] << " " << ans[1] << "\n~\n";
    }
    return 0;
}
// } Driver Code Ends