//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int countTriplets(vector<int> &arr, int target) {
        // Code Here
            int n = arr.size();
    int cnt = 0;

    // Sort the array to apply two-pointer technique

    for (int i = 0; i < n - 2; i++) {  // Fix the first element
        int j = i + 1;  // Start of the second pointer
        int k = n - 1;  // Start of the third pointer

        while (j < k) {
            int sum = arr[i] + arr[j] + arr[k];

            if (sum == target) {
                // Handle duplicates for the second and third pointers
                if (arr[j] == arr[k]) {
                    int count = k - j + 1;
                    cnt += (count * (count - 1)) / 2; // Choose any two from 'count'
                    break;
                }

                int c1 = 1, c2 = 1;
                while (j + 1 < k && arr[j] == arr[j + 1]) {
                    c1++;
                    j++;
                }
                while (k - 1 > j && arr[k] == arr[k - 1]) {
                    c2++;
                    k--;
                }

                cnt += c1 * c2;
                j++;
                k--;
            } 
            else if (sum < target) {
                j++;
            } 
            else {
                k--;
            }
        }
    }
    return cnt;
    }
};

//{ Driver Code Starts.

vector<int> lineArray() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> arr;
    int num;
    while (ss >> num) {
        arr.push_back(num);
    }
    return arr;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr = lineArray();
        int target;
        cin >> target;
        cin.ignore();

        Solution ob;
        int res = ob.countTriplets(arr, target);
        cout << res << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends