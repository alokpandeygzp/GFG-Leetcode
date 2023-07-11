//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minRow(int N, int M, vector<vector<int>> arr) 
    {
        vector<int> v;
        int sum;
        for(int i=0;i<N;i++)
        {
            sum=0;
            for(int j=0;j<M;j++)
                sum+=arr[i][j];
            v.push_back(sum);
        }
        int min=INT_MAX, ans=-1;;
        for(int i=0;i<v.size();i++)
        {
            if(min>v[i])
            {
                min=v[i];
                ans=i+1;
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
        int N, M;
        cin >> N >> M;
        vector<vector<int>> A(N, vector<int>(M));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> A[i][j];
            }
        }
        Solution ob;
        cout << ob.minRow(N, M, A) << "\n";
    }
}
// } Driver Code Ends