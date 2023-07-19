//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void heapify(vector<int>& arr, int n, int i) 
    {
        int largest=i; // Initialize the largest element as the root
        int left=2*i+1; 
        int right=2*i+2; 
    
        // Compare the left child with the root
        if(left<n && arr[left]>arr[largest])
            largest=left;
    
        // Compare the right child with the largest so far
        if(right<n && arr[right]>arr[largest])
            largest=right;
    
        // If the largest element is not the root, swap them and recursively heapify the affected subtree
        if(largest!=i)
        {
            swap(arr[i],arr[largest]);
            heapify(arr,n,largest);
        }
    }
    void convertMinToMaxHeap(vector<int> &arr, int N)
    {
        // Start from the last non-leaf node and heapify each node
        for(int i=N/2-1;i>=0;i--)
            heapify(arr,N,i);
    }
    
};


//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> vec(n);
       for(int i = 0;i<n;i++) cin >> vec[i];

        Solution obj;
        obj.convertMinToMaxHeap(vec,n);
        for(int i = 0;i<n;i++) cout << vec[i] << " ";
        cout << endl;
        

        
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends