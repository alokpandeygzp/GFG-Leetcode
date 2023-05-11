//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int findMinimum(int arr[], int low, int high, int key)
    {
        if(arr[0]<arr[high])
            return 0;
    
        while(low<high)
        {
          int mid=low+(high-low)/2;
          
          if(arr[low]<=arr[mid] && arr[high]<=arr[mid])
            low=mid+1;
          else 
            high=mid;
        }
       return low;
    }
    int BS(int arr[],int low,int high,int key)
    {
        while(low<=high)
        {
            int mid=low+(high-low)/2;
          
            if(arr[mid]==key)
                return mid;
            else if(arr[mid]<key)
                low=mid+1;
            else 
                high=mid-1;
        }
       return -1;
    }
    int search(int arr[], int low, int high, int key){
        
        int mini=findMinimum(arr,low,high,key);
        
        int ans1=BS(arr,low,mini-1,key);
        int ans2=BS(arr,mini,high,key);
        
        if(ans1==-1 && ans2==-1)
            return -1;
        else
            return (ans1>=0)?ans1:ans2;
    }
};

//{ Driver Code Starts. 
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
return 0;
}
// } Driver Code Ends