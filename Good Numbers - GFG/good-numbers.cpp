//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    bool checkGood(int n,int D)
    {
        int dig=n%10;
        if(dig==D)
            return false;
        int sum=dig;
        n=n/10;
        
        while(n>0)
        {
            dig=n%10;
            if(dig<=sum || dig==D)
                return false;
            sum=sum+dig;
            n=n/10;
        }
        return true;
    }
    vector<int> goodNumbers(int L, int R, int D) {
        vector<int> ans;
        for(int i=L;i<=R;i++)
        {
            if(checkGood(i,D))
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int L, R, D;
        cin >> L >> R >> D;
        Solution ob;
        vector<int> ans = ob.goodNumbers(L, R, D);
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
}
// } Driver Code Ends