//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

// Back-end complete function Template for C++

class Solution {
  public:
    long long solve(vector<int>& burstTimes) 
    {
        sort(burstTimes.begin(),burstTimes.end());
        
        int n = burstTimes.size();
        vector<int> waitingTimes(n, 0);
        float totalWaitingTime = 0;
    
        for(int i=1;i<n;i++)
        {
            waitingTimes[i]=waitingTimes[i-1]+burstTimes[i-1];
            totalWaitingTime+=waitingTimes[i];
        }
    
        float avgWaitingTime = totalWaitingTime/n;
        return (long long)avgWaitingTime;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> bt(n), p(n);
        for (int i = 0; i < n; i++) {
            cin >> bt[i];
        }
        Solution obj;
        long long ans = obj.solve(bt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends