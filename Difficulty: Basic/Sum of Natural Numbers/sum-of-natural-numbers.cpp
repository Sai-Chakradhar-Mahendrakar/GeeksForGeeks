class Solution {
  public:
    int findSum(int n) {
        if(n==0) return 0;
        return n+findSum(n-1);
    }
};
