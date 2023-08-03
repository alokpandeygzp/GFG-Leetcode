//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long mod=1e9+7;
    long long f(int i, int j,vector<vector<long long int>> &dp)
    {
        if(i==0 && j==0)    return 1;
        else if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1)    return dp[i][j];
        
        long long int left=(f(i-1,j,dp))%mod;
        long long int right=(f(i,j-1,dp))%mod;
        
        return dp[i][j]=(left+right)%mod;
    }
    long long int numberOfPaths(int m, int n)
    {
        vector<vector<long long int>> dp(m+1,vector<long long int>(n+1,-1));
        return f(m-1,n-1,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> m >> n;
        Solution ob;
        cout<<ob.numberOfPaths(m,n)<<endl;
    }
    return 0;
}

// } Driver Code Ends