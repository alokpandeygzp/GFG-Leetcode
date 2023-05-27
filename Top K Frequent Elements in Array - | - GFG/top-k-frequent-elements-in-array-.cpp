//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    static bool myCmp(pair<int,int> &a, pair<int,int> &b)
    {
        if(a.second==b.second)
            return a.first>b.first;
        return a.second>b.second;
    }
    vector<int> topK(vector<int>& nums, int k) {
        
        vector<pair<int,int>> mp;
        map<int,int> m;
        
        for(int i=0;i<nums.size();i++)
            m[nums[i]]++;
        
        for(auto it:m)
            mp.push_back({it.first,it.second});
        
        sort(mp.begin(), mp.end(), myCmp);
        
        int count=1;
        vector<int> ans;
        for(auto it:mp)
        {
            if(count<=k)
            {
                ans.push_back(it.first);
                count++;
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &i : nums) cin >> i;
        int k;
        cin >> k;
        Solution obj;
        vector<int> ans = obj.topK(nums, k);
        for (auto i : ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends