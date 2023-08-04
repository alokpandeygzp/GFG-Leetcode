//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    // function to find totient of n
    long long ETF(int n) 
    {
    long long result = n; // Initialize result with n

    // Iterate through all prime factors of n
    for (long long i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            // i is a prime factor of n
            while (n % i == 0) {
                n /= i;
            }
            // Reduce result using the formula
            result -= result / i;
        }
    }

    // If n is still greater than 1, it's a prime factor
    if (n > 1) {
        result -= result / n;
    }

    return result;
}

};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        long long N;
        cin>>N;
        Solution ob;
        cout << ob.ETF(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends