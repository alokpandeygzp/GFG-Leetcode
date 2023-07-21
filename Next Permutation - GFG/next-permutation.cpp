//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> arr)
    {
        //Step 1: finding break point
        int ind=-1;
        for(int i=N-2;i>=0;i--)
        {
            if(arr[i]<arr[i+1])
            {
                ind=i;
                break;
            }
        }
        
        //If break point doesn't exist
        if(ind==-1)
        {
            reverse(arr.begin(),arr.end());
            return arr;
        }
        
        //Step 2: finding greater elt from right
        for(int i=N-1;i>=ind;i--)
        {
            if(arr[i]>arr[ind])
            {
                swap(arr[i],arr[ind]);
                break;
            }
        }
        
        //Step 3: reversing the right half
        reverse(arr.begin()+ind+1,arr.end());
        return arr;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends