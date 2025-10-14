class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        int sum=0;
        int maxLen=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            
            if(sum==k){
                maxLen=i+1;
            }
            
            if(mp.find(sum-k)!=mp.end()){
                maxLen = max(maxLen, i-mp[sum-k]);
            }
            
            if(mp.find(sum)==mp.end()){
                mp[sum]=i;
            }
        }
        return maxLen;
    }
};
