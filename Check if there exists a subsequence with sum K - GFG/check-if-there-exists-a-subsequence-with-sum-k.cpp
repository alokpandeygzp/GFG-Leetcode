//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    bool f(int n,vector<int>& arr, int k, int sum,vector<vector<int>>& dp)
    {
        if(n<0)        return (sum==k);
        if(sum==k)      return true;
        if(dp[n][sum]!=-1)   return dp[n][sum];
        
        bool pick=false;
        
        if(sum+arr[n]<=k)
            pick=f(n-1,arr,k,sum+arr[n],dp);
        bool notPick=f(n-1,arr,k,sum,dp);
        
        return dp[n][sum]=pick||notPick;
    }
    bool checkSubsequenceSum(int n,vector<int>& arr, int k)
    {
        vector<vector<int>> dp(n,vector<int>(k+1, -1));
        return f(n-1,arr,k,0,dp);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int> arr;
        
        for(int i=0; i<n; ++i){
            int x; cin>>x;
            arr.push_back(x);
        }
        
        Solution obj;
        bool ans = obj.checkSubsequenceSum(n, arr, k);
        cout<<( ans ? "Yes" : "No")<<"\n";
    }
    return 0;
}
// } Driver Code Ends