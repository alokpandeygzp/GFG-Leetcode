//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void print_divisors(int n) {
        
        int i;

        for(i=1;i*i<n;i++)
        {
            if(n%i==0)
                cout<<i<<" ";
        }
    
        if(i*i==n)
            cout<<i<<" ";
    
        for(i=i-1;i>=1;i--) {
            if (n%i==0)
                cout<<(n/i)<<" ";
        }
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        Solution ob;
        ob.print_divisors(n);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends