//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
    bool isValid(int arr[], int n, int k, int mid){
        int sum=0,st=1;
        for(int i=0;i<n;i++){   
            sum+=arr[i];
            if(sum>mid){
                sum=arr[i];
                st++;
            }
        }
        return (st<=k);
    }
    int leastWeightCapacity(int arr[], int n, int k) {
        if(n<k) return -1;
        int maxi=INT_MIN, sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(arr[i]>maxi) maxi=arr[i];
        }        
        int low=maxi, high=sum, res=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isValid(arr,n,k,mid)==true){
                res=mid;
                high=mid-1;
            }
            else    low=mid+1;
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,D;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr,N,D) << endl;
    }
    return 0;
}
// } Driver Code Ends