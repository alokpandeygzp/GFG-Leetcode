//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) 
	{
	    long long prod1=arr[0], prod2=arr[0], result=arr[0];
	    for(int i=1;i<n;i++)
	    {
	        long long temp=max({(long long)arr[i],prod1*arr[i],prod2*arr[i]});
	        prod2=min({(long long)arr[i],prod1*arr[i],prod2*arr[i]});
	        prod1=temp;
	        result=max(result,prod1);
	    }
	    return result;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends