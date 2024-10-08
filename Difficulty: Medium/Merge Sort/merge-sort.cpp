//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
    public:
    void merge(int arr[], int l, int r)
    {
         // Your code here
         int i=l;
         int m=(l+r)/2;
         int j=m+1;
         
         vector<int> temp;
         
         while(i<=m and j<=r){
             if(arr[i]>arr[j]){
                 temp.push_back(arr[j++]);
             }
             else{
                 temp.push_back(arr[i++]);
             }
         }
         
         while(i<=m){
             temp.push_back(arr[i++]);
         }
         
         while(j<=r){
             temp.push_back(arr[j++]);
         }
         
         int k=0;
         for(int idx=l;idx<=r;idx++){
             arr[idx] = temp[k++];
         }
         
         return;
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        if(l>=r){
            return;
        }
        
        int mid = (l+r)/2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        merge(arr, l, r);
        
        return;
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends