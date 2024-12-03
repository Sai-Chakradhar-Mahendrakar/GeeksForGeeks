//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int> > &arr) {
        // code here
        int m=arr.size();
        int n=arr[0].size();
        int cnt=0;
        int idx=-1;
        for(int i=0;i<m;i++){
            // auto it = lower_bound(arr[i].begin(), arr[i].end(), 1);
            // int cnt_ = n - (it - arr[i].begin());
            int cnt_ = n- lowerBound(arr[i], n, 1);
            if(cnt_>cnt){
                cnt=cnt_;
                idx=i;
            }
        }
        return idx;
    }
  private:
    int lowerBound(vector<int>&arr, int m, int i){
        int s=0;
        int e=m-1;
        int ans=m;
        while(s<=e){
            int mid = (s+e)/2;
            if(arr[mid]>=i){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }   
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after the integer input
    while (t--) {
        string input;
        getline(cin, input);
        vector<vector<int>> mat;
        string innerArray;
        bool isInsideArray = false;

        for (char c : input) {
            if (c == '[') {
                if (isInsideArray) {
                    innerArray.clear();
                }
                isInsideArray = true;
            } else if (c == ']') {
                if (isInsideArray && !innerArray.empty()) {
                    vector<int> row;
                    stringstream ss(innerArray);
                    int num;

                    while (ss >> num) {
                        row.push_back(num);
                        if (ss.peek() == ',')
                            ss.ignore();
                        while (isspace(ss.peek()))
                            ss.ignore();
                    }

                    mat.push_back(row);
                    innerArray.clear();
                }
                isInsideArray = false;
            } else if (isInsideArray) {
                if (!isspace(c)) {
                    innerArray += c;
                }
            }
        }

        Solution obj;
        cout << obj.rowWithMax1s(mat);
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends