//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(int n, int start[], int end[]) {
        // Your code here
        vector<pair<int, int>> mt;
        for(int i=0;i<n;i++){
            mt.push_back({start[i], end[i]});
        }
        
        sort(mt.begin(), mt.end(), cmp);
        
        int last = mt[0].second;
        int cnt=1;
        
        for(int i=1;i<mt.size();i++){
            if(mt[i].first>last){
                cnt++;
                last=mt[i].second;
            }
        }
        
        return cnt;
    }
  private:
    bool static cmp(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++)
            cin >> start[i];

        for (int i = 0; i < n; i++)
            cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(n, start, end);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends