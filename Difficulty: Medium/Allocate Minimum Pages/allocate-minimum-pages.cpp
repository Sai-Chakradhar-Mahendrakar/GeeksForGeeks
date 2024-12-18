//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int findPages(vector<int> &arr, int k) {
        
        if(arr.size()<k){
            return -1;
        }
        // code here
        int s=*max_element(arr.begin(), arr.end());
        int e=accumulate(arr.begin(), arr.end(), 0);
        
        while(s<=e){
            int mid=(s+e)/2;
            if(canAllocate(arr, k, mid)){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return s;
    }
  private:
    bool canAllocate(vector<int>& arr, int k, int mid){
        int cnt=1;
        int bookPages=0;
        for(int i=0;i<arr.size();i++){
            if(bookPages+arr[i]>mid){
                cnt++;
                bookPages=0;
            }
            bookPages+=arr[i];
        }
        return cnt>k;
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.findPages(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends