// User function template for C++
class Solution {
  public:
    vector<int> findSubarray(vector<int>& arr) {
        long bestSum=-1;
        long currSum=0;
        
        int bestStart=-1;
        int bestLen=0;
        
        int start=0;
        
        for(int i=0;i<arr.size();i++){
            if(arr[i]>=0){
                currSum+=arr[i];
                int currLen=i-start+1;
                
                if((currSum>bestSum) ||
                   (currSum==bestSum && currLen>bestLen) ||
                   (currSum==bestSum && currLen==bestLen && start<bestStart)
                ){
                    bestSum=currSum;
                    bestStart=start;
                    bestLen=currLen;
                }
            } else {
                currSum=0;
                start=i+1;
            }
        }
        
        if(bestStart==-1) return {-1};
        
        return vector<int>(arr.begin()+bestStart, arr.begin()+bestStart+bestLen);
    }
};