//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends


class Solution{
  public:
    long long countSubArrayProductLessThanK(const vector<int>& arr, int n, long long k) {
        int i=0,j=0;
        long long product=1;
        long long ans=0;
        
        while(j<n) 
        {
            product*=arr[j];
    
            while(i<=j && product>=k)
            {
                product/=arr[i];
                i++;
            }
                
            ans+=(j-i+1);
            j++;
        }
        return ans;
    }

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends