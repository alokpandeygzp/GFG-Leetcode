//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
  
    int minJumps(int A[], int N){
        int longestReach=0;
        int count=0;
        int currReach=0;
        
        for(int i=0;i<N-1;i++)
        {
            longestReach=max(longestReach, A[i]+i);
            if(i==currReach)
            {
                currReach=longestReach;
                count++;
            }
        }
        
        if(currReach<N-1)
            return -1; // The end is not reachable
        return count;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends