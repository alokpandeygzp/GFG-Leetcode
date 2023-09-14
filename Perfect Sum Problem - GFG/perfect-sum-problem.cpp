//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int f(int n, int arr[], int k, int sum, vector<vector<int>>& dp)
    {
        if(n<0)         return (sum==k)?1:0;
        if(dp[n][sum]!=-1)   return dp[n][sum];
        
        int pick=0;
        
        if(sum+arr[n]<=k)
            pick=f(n-1,arr,k,sum+arr[n],dp);
        int notPick=f(n-1,arr,k,sum,dp);
        
        return dp[n][sum]=(pick+notPick)%1000000007;
    }
	int perfectSum(int arr[], int n, int k)
	{
        vector<vector<int>> dp(n,vector<int>(k+1, -1));
        return f(n-1,arr,k,0,dp);
	}
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends