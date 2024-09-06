//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
        // code here
        int m=arr1.size();
        int n=arr2.size();
        
        if(m>n){
            kthElement(k, arr2, arr1);
        }
        
        // Search Within a Range
        int s=max(0, k-n); // max n=5 k=7
        int e=min(k,m);  // left subarr 
        
        while(s<=e){
            int px=(s+e)/2;
            int py=k-px;
            
            int x1=(px==0)? INT_MIN: arr1[px-1];
            int x2=(py==0)? INT_MIN: arr2[py-1];
            int x3=(px==m)? INT_MAX: arr1[px];
            int x4=(py==n)? INT_MAX: arr2[py];
            
            if(x1<=x4 && x2<=x3){
                return max(x1, x2);
            }
            else if(x1>x4){
                e=px-1;
            }
            else{
                s=px+1;
            }
        }
        return -1; 
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> arr1, arr2;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr1.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            arr2.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(k, arr1, arr2) << endl;
    }
    return 0;
}
// } Driver Code Ends