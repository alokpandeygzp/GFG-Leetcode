//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) 
    {
        if(grid.empty()) 
            return 0;
            
        int m = grid.size();
        int n = grid[0].size();
        int days = 0, tot = 0, cnt = 0;
        
        queue<pair<int, int>> q;
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(grid[i][j] != 0) tot++;
                if(grid[i][j] == 2) q.push({i, j});
            }
        }
        
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        
        while(!q.empty())
        {
            int k=q.size();
            cnt+=k; 
            while(k--)
            {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                
                for(int i = 0; i < 4; ++i)
                {
                    int nrow=row+dx[i];
                    int ncol=col+dy[i];
                    
                    if(nrow<0 || ncol<0 || nrow>=m || ncol>=n || grid[nrow][ncol]!=1) 
                        continue;
                    
                    grid[nrow][ncol]=2;
                    q.push({nrow, ncol});
                }
            }
            
            if(!q.empty()) 
                days++;
        }
        return tot == cnt ? days : -1;
    }

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends