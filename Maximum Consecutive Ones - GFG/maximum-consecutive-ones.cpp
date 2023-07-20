//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int longestOnes(int n, vector<int>& nums, int k) {
        int i=0,j=0,sum=0;
        int maxi=INT_MIN;
        while(j<n)
        {
            sum+=nums[j];
            
            if(j-i+1-sum<=k)
            {
                maxi=max(maxi,j-i+1);
                j++;
            }
            else
            {
                while(j-i+1-sum>k)
                {
                    sum-=nums[i];
                    i++;
                }
                if(j-i+1-sum==k)
                    maxi=max(maxi,j-i+1);
                j++;
            }
        }
        return maxi;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            nums.push_back(x);
        }

        int k;
        cin >> k;

        Solution obj;
        cout << obj.longestOnes(n, nums, k) << endl;
    }
    return 0;
}
// } Driver Code Ends