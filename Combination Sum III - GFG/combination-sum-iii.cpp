//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void f(int ind,int K,int N,vector<int> &ds,vector<vector<int>> &ans)
    {
        if(N==0 && K==0)
        {
            ans.push_back(ds);
            return;
        }
        
        for(int i=ind;i<=9;i++)
        {
            if(i>N) break;
            
            ds.push_back(i);
            f(i+1,K-1,N-i,ds,ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum(int K, int N) {
        vector<vector<int>> ans;
        vector<int> ds;
        
        f(1,K,N,ds,ans);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K >> N;

        Solution obj;
        vector<vector<int>> ans = obj.combinationSum(K, N);
        sort(ans.begin(), ans.end());
        for (auto &arr : ans) {
            for (auto it : arr) cout << it << ' ';
            cout << endl;
        }
    }
    return 0;
}
// } Driver Code Ends