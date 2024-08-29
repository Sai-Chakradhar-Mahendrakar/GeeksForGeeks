//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string s) {
        // Your code here
        stack<char> st;
        string res;
        
        auto precedence = [](char op) {
            if (op == '^') return 3;
            if (op == '*' || op == '/') return 2;
            if (op == '+' || op == '-') return 1;
            return -1;
        };
        
        for(auto ch:s){
            if(isalnum(ch)){
                res+=ch;
            }
            else if(ch=='('){
                st.push(ch);
            }
            else if(ch==')'){
                while(!st.empty() and st.top()!='('){
                    res+=st.top();
                    st.pop();
                }
                if(!st.empty()){
                    st.pop();
                }
            }
            else{
                while(!st.empty() and precedence(ch)<=precedence(st.top())){
                    res+=st.top();
                    st.pop();
                }
                st.push(ch);
            }
        }
        
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        
        return res;
    }
};


//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends