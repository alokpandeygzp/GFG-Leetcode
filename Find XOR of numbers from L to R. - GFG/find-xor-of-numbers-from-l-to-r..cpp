//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int f(int n)
    {
        int x=n%4;
        if(x==0)        return n;
        else if(x==1)   return 1;
        else if(x==2)   return n+1;
        else            return 0;
    }
    int findXOR(int l, int r) {
        return f(l-1)^f(r);
    }
};

//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    while (t--) {
        // Input

        int l, r;
        cin >> l >> r;

        Solution obj;
        cout << obj.findXOR(l, r) << endl;
    }
}
// } Driver Code Ends