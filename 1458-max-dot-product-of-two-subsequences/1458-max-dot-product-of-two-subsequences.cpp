class Solution {
public:
    int f(int i,int j,vector<int>& nums1, vector<int>& nums2,vector<vector<int>> &dp)
    {
        if(i<0 || j<0)
            return -1e8;
        if(dp[i][j]!=-1)    return dp[i][j];
            
        int notPick=f(i-1,j-1,nums1,nums2,dp);
        int pick=max(nums1[i]*nums2[j],f(i-1,j-1,nums1,nums2,dp)+nums1[i]*nums2[j]);
        int maxi=max(f(i-1,j,nums1,nums2,dp),f(i,j-1,nums1,nums2,dp));
        
        return dp[i][j]=max(max(pick,notPick),maxi);
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) 
    {
        int n=nums1.size()-1;
        int m=nums2.size()-1;
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return f(n,m,nums1,nums2,dp);
    }
};