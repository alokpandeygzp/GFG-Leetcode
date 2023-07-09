//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    void swap(int *p, int *q) {
        int temp = *p;
        *p = *q;
        *q = temp;
    }

    int missingNumber(int arr[], int n) 
    {
        int count = 0;
    
        // Move all positive elements to the left side
        for (int i = 0; i < n; i++) {
            if (arr[i] > 0) {
                swap(&arr[count], &arr[i]);
                count++;
            }
        }
    
        // Mark elements as negative based on their values
        for (int i = 0; i < count; i++) {
            int temp = abs(arr[i]) - 1;
            if (temp < count && arr[temp] > 0) {
                arr[temp] = -arr[temp];
            }
        }
    
        // Find the smallest positive missing number
        for (int i = 0; i < count; i++) {
            if (arr[i] > 0) {
                return i + 1;
            }
        }
    
        return count + 1;
    }

};

//{ Driver Code Starts.

int missingNumber(int arr[], int n);

int main() { 
    
    //taking testcases
    int t;
    cin>>t;
    while(t--){
        
        //input number n
        int n;
        cin>>n;
        int arr[n];
        
        //adding elements to the array
        for(int i=0; i<n; i++)cin>>arr[i];
        
        Solution ob;
        //calling missingNumber()
        cout<<ob.missingNumber(arr, n)<<endl;
    }
    return 0; 
} 
// } Driver Code Ends