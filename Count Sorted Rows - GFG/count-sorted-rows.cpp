//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int sortedCount(int n, int m, vector<vector<int>> mat) {
    
        int count=n;
        for(int i=0;i<n;i++)
        {
            int incOrder=(mat[i][0]<mat[i][1])?1:0;
                
            //Increasing Order
            if(incOrder==1)
            {
                for(int j=0;j<m-1;j++)
                {
                    if(mat[i][j]>=mat[i][j+1])
                    {
                        count--;
                        break;
                    }
                }
            }
            //Decreasing Order
            else
            {
                for(int j=0;j<m-1;j++)
                {
                    if(mat[i][j]<=mat[i][j+1])
                    {
                        count--;
                        break;
                    }
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
        int N, M;
        cin >> N >> M;
        vector<vector<int>> Mat(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> Mat[i][j];
        Solution ob;
        cout << ob.sortedCount(N, M, Mat) << "\n";
    }
}
// } Driver Code Ends