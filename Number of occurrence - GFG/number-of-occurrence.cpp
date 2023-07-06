//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
    int findLeft(int arr[], int n, int x)
    {
        int low=0,high=n-1;
        int ansLeft=-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(arr[mid]==x)
            {
                ansLeft=mid;
                high=mid-1;
            }
            else if(arr[mid]<x)
                low=mid+1;
            else
                high=mid-1;
        }
        return ansLeft;
    }
    int findRight(int arr[], int n, int x)
    {
        int low=0,high=n-1;
        int ansRight=-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(arr[mid]==x)
            {
                ansRight=mid;
                low=mid+1;
            }
            else if(arr[mid]<x)
                low=mid+1;
            else
                high=mid-1;
        }
        return ansRight;
    }
	int count(int arr[], int n, int x) {
	    int l=findLeft(arr,n,x);
	    int r=findRight(arr,n,x);
	    if(l==-1 && r==-1)
	        return 0;
	    return r-l+1;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends