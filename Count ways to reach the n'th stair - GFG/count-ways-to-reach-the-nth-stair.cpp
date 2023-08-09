//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
    int mod=1e9+7;
    int f(int i,vector<int> &dp)
    {
        if(i<=0)        return 1;
        if(dp[i]!=-1)   return dp[i];
        
        int left=f(i-1,dp)%mod;
        int right=f(i-2,dp)%mod;
        
        return dp[i]=(left+right)%mod;
    }
    int countWays(int n)
    {
        vector<int> dp(n+1,-1);
        return f(n-1,dp);
    }
};



//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}

// } Driver Code Ends