//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    void merge(vector<int>& res, vector<int>& arr1, vector<int>& arr2)
    {
        int n=arr1.size(), m=arr2.size();
        int i=0, j=0;
        while(i<n && j<m)
        {
            if(arr1[i]<=arr2[j])
                res.push_back(arr1[i++]);
            else
                res.push_back(arr2[j++]);
        }
        while(i<n)
            res.push_back(arr1[i++]);
    
        while(j<m)
            res.push_back(arr2[j++]);
        
    }
    double MedianOfArrays(vector<int>& arr1, vector<int>& arr2)
    {
        int n=arr1.size(), m=arr2.size();
        vector<int> res;
        merge(res, arr1, arr2);
        
        if((n+m)%2==0)
            return (res[((n+m)/2.0)-1]+res[((n+m)/2.0)])/2.0;
        else
            return res[(n+m)/2];
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}



// } Driver Code Ends