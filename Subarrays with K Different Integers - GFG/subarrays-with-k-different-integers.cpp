//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int atmost(vector<int> &arr,int N,int k)
    {
        int i=0,j=0;
        vector<int> mp(N+1,0);
        int count=0,ans=0;
        
        while(j<N)
        {
            //New distinct elt appears
            if(mp[arr[j]]==0)
               count++;
            
            mp[arr[j]]++;
            while(count>k)
            {
                mp[arr[i]]--;
                
                // if count is 0, mtlb wo distinct elt bahar nikal gya
                if(mp[arr[i]]==0)
                  count--;
                i++;
            } 
            ans+=j-i+1;
            j++;
        }
        return ans;
    }
    int subarrayCount(vector<int> &arr, int N, int k) 
    {
        // By subtracting the count of subarrays with at most 'k-1' distinct elements
        // from the count of subarrays with at most 'k' distinct elements,
        // we get the count of subarrays with exactly 'k' distinct elements.
        int answer=0;
        int first=atmost(arr,N,k);
        int second=atmost(arr,N,k-1);
        answer=first-second;
        return answer;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, k;
        cin >> N >> k;

        vector<int> arr(N);
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution obj;
        cout << obj.subarrayCount(arr, N, k) << endl;
    }
    return 0;
}
// } Driver Code Ends