//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value;
    int weight;
};


// } Driver Code Ends
// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, Item arr[], int n) {
        // Your code here
        priority_queue<pair<double, int>> pq;
        
        for(int i=0;i<n;i++){
            pq.push({((double)arr[i].value/arr[i].weight), i});
        }
        
        double maxCost=0;
        while(w && !pq.empty()){
            auto topItem = pq.top();
            pq.pop();
            int val=arr[topItem.second].value;
            int wt=arr[topItem.second].weight;
            
            if(wt<=w){
                maxCost+=val;
                w-=wt;
            }
            else{
                maxCost+=(topItem.first*w);
                w=0;
            }
        }
        return maxCost;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    // taking testcases
    cin >> t;
    cout << setprecision(6) << fixed;
    while (t--) {
        // size of array and weight
        int n, W;
        cin >> n >> W;

        Item arr[n];
        // value and weight of each item
        for (int i = 0; i < n; i++) {
            cin >> arr[i].value >> arr[i].weight;
        }

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(W, arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends