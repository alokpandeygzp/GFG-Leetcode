//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    long long MOD=1000000007;
    long long f(int ind, vector<long long> &dp)
    {
        if(ind<0)   return 0;
        if(ind==0)  return dp[ind]=1;
        if(dp[ind]!=-1) return dp[ind];
        
        long long first=f(ind-1,dp)%MOD;
        long long second=f(ind-2,dp)%MOD;
        long long third=f(ind-3,dp)%MOD;
        
        return dp[ind]=(first+second+third)%MOD;
    }
    long long countWays(int n)
    {
        vector<long long> dp(n+1,-1);
        return f(n,dp);
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends