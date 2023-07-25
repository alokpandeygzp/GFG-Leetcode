//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int canReach(int A[], int N) 
    {
        int longestReach=0,currReach=0;
        
        for(int i=0;i<N;i++)
        {
            if(i>longestReach)  return false;
            
            currReach=i+A[i];
            longestReach=max(longestReach, currReach);
        }
        return (longestReach>=N-1);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.canReach(A,N) << endl;
    }
    return 0;
}
// } Driver Code Ends