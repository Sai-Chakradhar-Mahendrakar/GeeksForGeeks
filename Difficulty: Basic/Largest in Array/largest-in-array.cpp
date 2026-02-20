class Solution {
  public:
    int largest(vector<int> &arr) {
        int maxEmt=INT_MIN;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>maxEmt){
                maxEmt=arr[i];
            }
        }
        return maxEmt;
    }
};
