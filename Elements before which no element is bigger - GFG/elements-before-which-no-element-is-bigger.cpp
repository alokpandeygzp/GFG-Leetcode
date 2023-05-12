//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    long long countElements(long long arr[], long long n) 
    {
        long long maxi=INT_MIN, prevMax=INT_MIN;
        long long count=0;
        
        for(int i=0;i<n;i++)
        {
            maxi=(maxi<arr[i])?arr[i]:maxi;
            if(prevMax!=maxi)
                count++;
            
            prevMax=maxi;
        }
        return count;
    }
};


//{ Driver Code Starts.
int main()
 {
	long long t;
	cin>>t;
	while(t--)
	{
	    long long n;
	    cin>>n;
	    long long a[n];
	    for(long long i=0;i<n;i++)
	        cin>>a[i];
	    Solution ob;
	    cout<<ob.countElements(a, n)<<endl;
	    
	}
	return 0;
}
// } Driver Code Ends