//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int aggressiveCows(vector<int> &stalls, int k) {
        sort(stalls.begin(), stalls.end());
        int n=stalls.size();
        int s=1;
        int e=stalls[n-1]-stalls[0];
        
        while(s<=e){
            int mid=(s+e)/2;
            if(canPlaceCow(stalls, k, mid)){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return e;
    }
  private:
    bool canPlaceCow(vector<int>& stalls, int k, int mid){
        int cnt=1;
        int lastCow = stalls[0];
        
        for(int i=1;i<stalls.size();i++){
            if(stalls[i]-lastCow>=mid){
                cnt++;
                lastCow=stalls[i];
            }
            if(cnt>=k){
                return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string in;
        getline(cin, in);
        stringstream sss(in);
        int num;
        while (sss >> num) {
            k = num;
        }
        Solution ob;
        int ans = ob.aggressiveCows(arr, k);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends