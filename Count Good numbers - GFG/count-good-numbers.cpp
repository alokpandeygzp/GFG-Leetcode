//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    const int MOD=1000000007;
    long long power(long long a, long long b) 
    {
        if(b==0)
            return 1;
    
        long long result=1;
        while(b>0)
        {
            if(b%2==1)
                result=(result*a)%MOD;
            a=(a*a)%MOD;
            b=b/2;
        }
        return result;
    }
    
    int countGoodNumbers(long long N)
    {
        long long evenCount=power(5,(N+1)/2);
        long long primeCount=power(4,N/2);
    
        long long totalCount=(evenCount*primeCount)%MOD;
        return totalCount;
    }

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        cin >> N;
        Solution ob;

        cout << ob.countGoodNumbers(N) << endl;
    }
}
// } Driver Code Ends