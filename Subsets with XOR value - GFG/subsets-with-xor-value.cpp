//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int f(int i, int x, int k, vector<int>&arr, int n)
    {
        if(i==n)
        {
            if(x==k)    return 1;
            else        return 0;
        }
        int notPick= f(i+1, x^arr[i],k,arr,n);
        int pick=    f(i+1, x,k,arr,n);
        return pick+notPick;
    }
    int subsetXOR(vector<int> arr, int N, int K) 
    {
        return f(0,0,K,arr,N);
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
        cin>>N;
        int K;
        cin>>K;
        vector<int> v;
        for(int i = 0;i<N;i++)
        {
            int x;
            cin>>x;
            v.push_back(x);
        }    
        Solution ob;
        cout << ob.subsetXOR(v,N,K) << endl;
    }
    return 0; 
}
// } Driver Code Ends