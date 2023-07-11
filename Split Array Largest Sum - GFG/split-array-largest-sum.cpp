//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int isValid(int arr[], int N, int K, int mid)
    {
        int count=0, sum=0;
        for(int i=0;i<N;i++)
        {
            sum+=arr[i];
            if(sum>mid)
            {
                count++;
                sum=arr[i];
            }
        }
        return count<K;
    }
    int splitArray(int arr[] ,int N, int K) 
    {
        int low=*max_element(arr,arr+N);
        int high=accumulate(arr,arr+N,0);
        int res=-1;
        
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(isValid(arr,N,K,mid))
            {
                res=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends