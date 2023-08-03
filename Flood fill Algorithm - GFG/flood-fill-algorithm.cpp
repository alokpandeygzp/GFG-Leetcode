//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void bfs(vector<vector<int>>& image, int sr, int sc, int newColor,vector<vector<int>> &visited)
    {
        int n=image.size();
        int m=image[0].size();
        
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int oldColor=image[sr][sc];
        while(!q.empty())
        {
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            
            if(!visited[row][col] && row>=0 && row<n && col>=0 && col<m && image[row][col]==oldColor)
            {
                visited[row][col]=1;
                image[row][col]=newColor;
                    
                if(row<n-1)
                    q.push({row+1,col});
                
                if(col<m-1)
                    q.push({row,col+1});
                
                if(row>0)
                    q.push({row-1,col});
                
                if(col>0)
                    q.push({row,col-1});
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        int n=image.size();
        int m=image[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        
        bfs(image,sr,sc,newColor,visited);
        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends