//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(const vector<int>& arr) {
    for (int num : arr)
        printf("%d ", num);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(vector<int>& arr, int low, int high)
    {
        // code here
        if(low>=high){
            return;
        }
        
        int pivotPosition = partition(arr, low, high);
        quickSort(arr, low, pivotPosition-1);
        quickSort(arr, pivotPosition+1, high);
    }
    
    public:
    int partition (vector<int>& arr, int low, int high)
    {
       // Your code here
       int pivot = arr[high];
       int i = low-1;
    //   cout<<i<<endl;
       for(int j=low;j<high;j++){
           if(arr[j]<pivot){
               i++;
               swap(arr[i], arr[j]);
           }
       }
       swap(arr[i+1], arr[high]);
       return i+1;
    }
};



//{ Driver Code Starts.

int main() {

    int T;
    scanf("%d", &T);
    getchar(); // to consume newline after T

    while (T--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        ob.quickSort(arr, 0, arr.size() - 1);
        printArray(arr);
    }

    return 0;
}

// } Driver Code Ends