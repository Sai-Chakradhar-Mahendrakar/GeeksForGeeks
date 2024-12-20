//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &mat) {
        // code here
        int startRow = 0;
        int endRow = mat.size()-1;
        int startCol = 0;
        int endCol = mat[0].size()-1;
        
        vector<int> ans;
        
        while(startRow<=endRow && startCol<=endCol){
            // startRow
            for(int i=startCol;i<=endCol;i++){
                ans.push_back(mat[startRow][i]);
            }
            
            // endCol
            for(int i=startRow+1;i<=endRow;i++){
                ans.push_back(mat[i][endCol]);
            }
            
            // endRow
            for(int i=endCol-1;i>=startCol;i--){
                if(startRow==endRow){
                    break;
                }
                ans.push_back(mat[endRow][i]);
            }
            
            // startCol
            for(int i=endRow-1;i>=startRow+1;i--){
                if(startCol==endCol){
                    break;
                }
                ans.push_back(mat[i][startCol]);
            }
            
            startRow++;
            endRow--;
            startCol++;
            endCol--;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r);

        for (int i = 0; i < r; i++) {
            matrix[i].assign(c, 0);
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends