//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string preToPost(string pre_exp) {
        stack<string> s;
        for(int i=pre_exp.size()-1;i>=0;i--){
            if (isOperator(pre_exp[i])) {
                string op1 = s.top(); 
                s.pop();
                string op2 = s.top(); 
                s.pop();
                string temp = op1 + op2 + pre_exp[i];
                s.push(temp);
            } 
            else{
                s.push(string(1, pre_exp[i]));
            }
        }
        return s.top();
    }
  private:
    bool isOperator(char ch){
        return ch=='+' || ch=='-' || ch=='/' || ch=='*';
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToPost(prefix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends