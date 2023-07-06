//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

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
vector<int> find(int arr[], int n, int x)
{
    vector<int> ans;
    ans.push_back(findLeft(arr,n,x));
    ans.push_back(findRight(arr,n,x));
    return ans;
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends