//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int rowWithMax1s(vector<vector<int>> arr, int n, int m) {
	    
	    int result=-1,maxi=INT_MIN;
	    for(int i=0;i<n;i++)
	    {
	        
	        int low=0, high=m-1;
	        int ans=-1;
	        
	        while(low<=high)
	        {
	            int mid=low+(high-low)/2;
	            
	            if(arr[i][mid]==1)
	            {
	                ans=mid;
	                high=mid-1;
	            }
	            else if(arr[i][mid]==0)
	                low=mid+1;
	        }
	        
	        if(ans==-1) ans=INT_MIN;
	        else        ans=m-ans;
	        
	       // cout<<ans<<"****"<<endl;
	        
	        if(maxi<ans)
	        {
	            maxi=ans;
	            result=i;
	        }
	        
	    }
	    return result;
	    
	}

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends