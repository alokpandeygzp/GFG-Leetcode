//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    
    bool isValid(int arr[], int n, int k, int mid)
    {
        int sum=0,st=1;
        for(int i=0;i<n;i++)
        {   
            sum+=arr[i];
            if(sum>mid){
                sum=arr[i];
                st++;
            }
        }
        return (st<=k);
    }
    int findPages(int arr[], int n, int k) 
    {
        if(n<k) return -1;
        
        //Pahle "Maximum" aur "Sum" nikalna hai
        int maxi=INT_MIN, sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            if(arr[i]>maxi)
                maxi=arr[i];
        }        
        
        int low=maxi, high=sum;
        int res=-1;
        
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            
            if(isValid(arr,n,k,mid)==true)
            {
                res=mid;
                high=mid-1;
            }
            else    low=mid+1;
            
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends