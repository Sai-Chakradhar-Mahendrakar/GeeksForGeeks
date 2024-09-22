//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string minWindow(string& str1, string& str2) {
        // Write your Code here
        int n=str1.size();
        int m=str2.size();
        int startWin=-1;
        int minWin=INT_MAX;
        
        for(int i=0;i<n;i++){
            if(str1[i]==str2[0]){
                int k=i;
                int j=0;
                while(k<n && j<m){
                    if(str1[k]==str2[j]){
                        j++;
                    }
                    k++;
                }
                
                if(j==m){
                    int end=k;
                    j=m-1;
                    k--;
                    while(j>=0){
                        if(str1[k]==str2[j]){
                            j--;
                        }
                        k--;
                    }
                    k++;
                    if(end-k<minWin){
                        minWin=end-k;
                        startWin=k;
                    }
                }
            }
        }
        return startWin==-1?"":str1.substr(startWin, minWin);
    }
};


//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string str1, str2;
        cin >> str1 >> str2;

        Solution obj;
        cout << obj.minWindow(str1, str2) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends