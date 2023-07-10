//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


int KthMissingElement(int a[], int n, int k);


int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        
        cout << KthMissingElement(a, n, k) << endl;
    
    }
    return 0;
}

// } Driver Code Ends


int KthMissingElement(int arr[], int n, int k)
{
     if(arr[n-1]-arr[0]==n-1)
        return -1;
    
    int low=0, high=n-1, missing;
    
    while(low<=high)
    {
        int mid=(low+high)/2;
        missing=arr[mid]-(arr[0]+mid);
        
        if(missing<k)
            low=mid+1;
        else
            high=mid-1;
    }
    if(arr[0]+high+k>arr[n-1])
        return -1;
        
    return arr[0]+high+k;
}