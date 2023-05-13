//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int findKRotation(int arr[], int n) {
	 
        if(arr[0]<arr[n-1])
            return 0;
    
        int low=0, high=n-1;
        
        while(low<high)
        {
          int mid=(low+high)/2;
          
          if(arr[low]<=arr[mid] && arr[high]<=arr[mid])
            low=mid+1;
          else 
            high=mid;
        }
        return low;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends