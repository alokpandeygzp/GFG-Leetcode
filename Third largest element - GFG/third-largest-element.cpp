//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    int thirdLargest(int arr[], int n)
    {
        priority_queue<int> pq;
        for(int i=0;i<n;i++)
            pq.push(arr[i]);
        
        int k=3;
        while(!pq.empty() && k>0)
        {
            int top=pq.top();
            pq.pop();
            k--;
            
            if(k==0)     return top;
        }
        return -1;
    }

};

//{ Driver Code Starts.
 
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution obj;
	    cout<<obj.thirdLargest(a,n)<<endl;
    }
}   
// } Driver Code Ends