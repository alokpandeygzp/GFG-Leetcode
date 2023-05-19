//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int closest3Sum(int arr[], int n, int x)
    {
        sort(arr,arr+n);
        
        int mini=INT_MAX,ans=0;
        for(int i=0;i<n;i++)
        {
            int j=i+1,k=n-1;
            while(j<k)
            {
                int sum=arr[i]+arr[j]+arr[k];
                    
                if(abs(x-sum)<mini)
                {
                    mini=abs(x-sum);
                    ans=sum;
                }
                if(sum>x)
                    k--;
                else if(sum<x)
                    j++;
                else
                    return sum;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int Arr[N];
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int X;
        cin>>X;
        Solution obj;
        cout<<obj.closest3Sum(Arr, N, X)<<endl;
    }
    return 0;
}
// } Driver Code Ends