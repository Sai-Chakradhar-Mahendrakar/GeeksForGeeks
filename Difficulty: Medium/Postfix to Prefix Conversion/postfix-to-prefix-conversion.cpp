//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string postToPre(string post_exp) {
        // Write your code here
        stack<string> s;
        for(int i=0;i<post_exp.size();i++){
            if(isOperator(post_exp[i])){
                auto op1 = s.top();
                s.pop();
                auto op2 = s.top();
                s.pop();
                string temp = post_exp[i]+op2+op1;
                s.push(temp);
            }
            else{
                s.push(string(1, post_exp[i]));
            }
        }
        return s.top();
    }
  private:
    bool isOperator(char ch){
        return ch=='+' || ch=='-' || ch=='*' || ch=='/';
    }
};

//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string postfix;
        cin >> postfix;

        // char marker; cin >> marker;

        Solution obj;
        cout << obj.postToPre(postfix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends