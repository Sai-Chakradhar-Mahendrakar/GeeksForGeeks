class Solution {
  public:
    void printTillN(int n) {
        if(n==0) return;
        printTillN(n-1);
        cout<<n<<" ";
    }
};