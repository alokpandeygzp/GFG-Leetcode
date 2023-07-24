//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{
  public:
    long long solve(int arr[], int n, int k) 
    {
        sort(arr,arr+n);
        long long ans1=0,ans2=0;
        int size=min(k,n-k);
        
        for(int i=0;i<size;i++)
            ans2+=arr[i];
        for(int i=size;i<n;i++)
            ans1+=arr[i];

        return ans1-ans2;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution obj;
        auto ans = obj.solve(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends