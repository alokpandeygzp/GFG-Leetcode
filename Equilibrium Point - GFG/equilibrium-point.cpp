//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long arr[], int n)
    {
        int sumL2R[n],sumR2L[n];
        
        sumL2R[0]=arr[0];
        sumR2L[n-1]=arr[n-1];
        
        for(int i=1;i<n;i++)
            sumL2R[i]=sumL2R[i-1]+arr[i];
        
        for(int i=n-2;i>=0;i--)
            sumR2L[i]=sumR2L[i+1]+arr[i];
        
        for(int i=0;i<n;i++)
        {
            if(sumR2L[i]==sumL2R[i])
                return i+1;
        }
        return -1;
    }

};

//{ Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends