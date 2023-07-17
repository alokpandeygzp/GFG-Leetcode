//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void f(int row,int col,vector<vector<int>> &m, int n,string str,vector<string> &ans)
    {
        if(row<0 || row>=n || col<0 || col>=n)  return;
        if(m[row][col]==0)  return;
        
        if(row==n-1 && col==n-1)
        {
            ans.push_back(str);
            return;
        }
        
        m[row][col]=0;
        
        str.push_back('D');
        f(row+1,col,m,n,str,ans);
        str.pop_back();
        
        str.push_back('U');
        f(row-1,col,m,n,str,ans);
        str.pop_back();
        
        str.push_back('R');
        f(row,col+1,m,n,str,ans);
        str.pop_back();
        
        str.push_back('L');
        f(row,col-1,m,n,str,ans);
        str.pop_back();
        
        m[row][col]=1;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        if(m[0][0]==0 || m[n-1][n-1]==0)
            return ans;
        f(0,0,m,n,"",ans);
        
        if(ans.empty())
            return {"-1"};
        
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends