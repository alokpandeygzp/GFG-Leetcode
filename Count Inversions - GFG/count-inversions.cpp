//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int merge(int low,int mid,int high,long long arr[],long long temp[])
    {
        int i=low,j=mid,k=low;
        long long int inv_count=0;
        
        while(i<=mid-1 && j<=high)
        {
            if(arr[i]<=arr[j])
                temp[k++]=arr[i++];
            else{
                temp[k++]=arr[j++];
                inv_count=inv_count+(mid-i);
            }
        }
        
        while(i<=mid-1)
            temp[k++]=arr[i++];
        
        while(j<=high)
            temp[k++]=arr[j++];
        
        for(int i=low;i<=high;i++)
            arr[i]=temp[i];
            
        return inv_count;
    }
    long long int mergeSort(int low,int high,long long arr[],long long temp[])
    {
        long long int inv_count=0;
        if(low<high)
        {
            int mid=low+(high-low)/2;
        
            inv_count+=mergeSort(low,mid,arr,temp);
            inv_count+=mergeSort(mid+1,high,arr,temp);
        
            inv_count+=merge(low,mid+1,high,arr,temp);
        }
        return inv_count;
    }
    long long int inversionCount(long long arr[], long long N)
    {
        long long temp[N];
        long long int inv_count=mergeSort(0,N-1,arr,temp);
        return inv_count;
    }
};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends