//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int findSubArraySum(int arr[], int n, int k)
    {
        unordered_map<int, int> mp;
        mp[0]=1;
        
        int count=0, sum=0;
        for(int i=0;i<n;i++) 
        {
            sum += arr[i];
            
            if(mp[sum-k])
                count += mp[sum-k];
            
            mp[sum]++;
        }
        
        return count;
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
        int k;
        cin>>k;
        Solution obj;
        cout<<obj.findSubArraySum(Arr, N, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends