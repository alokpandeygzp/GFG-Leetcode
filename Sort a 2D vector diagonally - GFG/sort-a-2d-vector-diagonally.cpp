//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void diagonalSort(vector<vector<int> >& grid, int n, int m)
    {
        for(int i=1;i<n;i++)
	    {
	        vector<int> diagonal;
	        int row=i;
	        int col=0;
	        
	        while(row<n && col<m)
	        {
	            diagonal.push_back(grid[row][col]);
	            row++;
	            col++;
	        }
	        
	        sort(diagonal.begin(), diagonal.end());
	        
	        row=i;
	        col=0;
	        int index=0;
	        while(row<n && col<m)
	        {
	            grid[row][col]=diagonal[index];
	            row++;
	            col++;
	            index++;
	        }
	        diagonal.clear();
	    }
	    
	    for(int j=1;j<m;j++)
	    {
	        vector<int> diagonal;
	        
	        int row=0;
	        int col=j;
	        while(row<n && col<m)
	        {
	            diagonal.push_back(grid[row][col]);
	            row++;
	            col++;
	        }
	        
	        sort(diagonal.begin(), diagonal.end(), greater<int>());
	        
	        row=0;
	        col=j;
	        int index=0;
	        while(row<n && col<m)
	        {
	            grid[row][col]=diagonal[index];
	            row++;
	            col++;
	            index++;
	        }
	        diagonal.clear();
	    }
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n>>m;

        int inputline2[n*m];
        for (int i = 0; i < n*m; ++i)
            cin>> inputline2[i];
        vector<vector<int> > matrix( n , vector<int> (m, 0));

        for(int i=0; i<n; i++) {
            for (int j = 0; j < m; ++j) {
                matrix[i][j] = inputline2[i * m + j]; 
            }
        }
        
        Solution ob;
        ob.diagonalSort(matrix, n, m);

        // print the modified matrix
        for (int i = 0; i < n; i++) { 
            for (int j = 0; j < m; j++) { 
                cout << matrix[i][j] << " "; 
            } 
            cout << endl; 
        }    
    }
    return 0;
}


// } Driver Code Ends