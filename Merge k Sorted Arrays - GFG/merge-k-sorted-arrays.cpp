//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++


class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeTwoArrays(vector<int> &arr1, vector<int> &arr2)
    {
        int n=arr1.size(), m=arr2.size();
        if(n==0) return arr2;
        if(m==0) return arr1;
        
        int i=0,j=0,k=0;
        vector<int> ans(n+m,0);
        
        while(i<n && j<m)
        {
            if(arr1[i]<arr2[j])
                ans[k++]=arr1[i++];
            else
                ans[k++]=arr2[j++];
        }
        while(i<n)
            ans[k++]=arr1[i++];
        
        while(j<m)
            ans[k++]=arr2[j++];
        
        return ans;
    }
    
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        vector<int> curr(arr[0].begin(),arr[0].end());
        
        for(int i=1;i<K;i++)
            curr=mergeTwoArrays(curr,arr[i]);
            
        return curr;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}






// } Driver Code Ends