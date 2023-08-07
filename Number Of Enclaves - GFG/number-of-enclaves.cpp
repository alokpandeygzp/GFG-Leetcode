//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
    void dfs(int i, int j, vector<vector<int>> &grid, int n, int m, vector<vector<int>> &vis)
    {
        vis[i][j]=1;
        int dr[]={0,-1,0,+1};
        int dc[]={-1,0,+1,0};
        
        for(int k=0;k<4;k++)
        {
            int row=i+dr[k];
            int col=j+dc[k];
            
            if(row>=0 && col>=0 && row<n && col<m && !vis[row][col] && grid[row][col]==1)
            {
                vis[row][col]=1;
                dfs(row,col,grid,n,m,vis);
            }
        }
    }
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) 
    {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if((i==0 || j==0 || i==n-1 || j==m-1) && !vis[i][j] && grid[i][j]==1)
                {
                    vis[i][j]=1;
                    dfs(i,j,grid,n,m,vis);
                }
            }
        }
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 && vis[i][j]==0)
                {
                    count++;
                }
            }
        }
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends