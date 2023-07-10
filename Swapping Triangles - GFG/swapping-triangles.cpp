//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int swap(int *a, int *b)
    {
        int temp=*a;
        *a=*b;
        *b=temp;
    }
    vector<vector<int>> swapTriangle(int n, vector<vector<int>> arr) {

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i>j)
                {
                    swap(&arr[i][j], &arr[j][i]);
                }
            }
        }
        return arr;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> A(N, vector<int>(N));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) cin >> A[i][j];
        Solution ob;
        vector<vector<int>> ans = ob.swapTriangle(N, A);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
}
// } Driver Code Ends