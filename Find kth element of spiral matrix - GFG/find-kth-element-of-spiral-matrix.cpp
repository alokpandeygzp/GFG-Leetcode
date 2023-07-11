//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int arr[MAX][MAX],int n,int m,int k)
    {
 		int left=0, top=0, right=m-1, bottom=n-1;
 		int count=0;
 		
 		while(left<=right && top<=bottom)
 		{
 		    for(int i=left;i<=right;i++)
 		    {
 		     //   cout<<arr[top][i]<<" (1) ";
 		        count++;
 		        if(count==k)
 		            return arr[top][i];
 		    }
 		    top++;
 		    
 		    for(int i=top;i<=bottom;i++)
 		    {
 		     //   cout<<arr[i][right]<<" (2) ";
 		        count++;
 		        if(count==k)
 		            return arr[i][right];
 		    }
 		    right--;
 		    
 		    for(int i=right;i>=left;i--)
 		    {
 		        count++;
 		     //   cout<<arr[bottom][i]<<" (3) ";
 		        if(count==k)
 		            return arr[bottom][i];
 		    }
 		    bottom--;
 		    
 		    for(int i=bottom;i>=top;i--)
 		    {
 		        count++;
 		     //   cout<<arr[i][left]<<" (4) ";
 		        if(count==k)
 		            return arr[i][left];
 		    }
 		    left++;
 		}
 		return -1;
    }
};





//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends