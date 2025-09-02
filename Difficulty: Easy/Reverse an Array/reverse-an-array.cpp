class Solution {
  public:
    void reverseArray(vector<int> &arr) {
        helper(arr, 0, arr.size()-1);
    }
    void helper(vector<int>& arr, int s, int l){
        if(s>=l){
            return;
        }
        swap(arr[s], arr[l]);
        helper(arr, s+1, l-1);
    }
};