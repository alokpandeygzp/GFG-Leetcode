//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int totalJumps(int x, int y, int n, int arr[])
    {
        int cnt=0;
        int i=0;
        while(i<n)
        {
            if(arr[i]<=x)
            {
                i++;
                cnt++;
            }
            else
            {
                arr[i]=arr[i]-(x-y);
                cnt++;
            }
        }
        return cnt++;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int X, Y, N;
        cin>>X>>Y>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.totalJumps(X, Y, N, arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends