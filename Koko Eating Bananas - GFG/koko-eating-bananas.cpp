//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool isValid(vector<int>& piles, int speed, int H) {
        int hours = 0;
        
        for (int bananas : piles)
            hours += ceil(static_cast<double>(bananas) / speed);
        
        return hours <= H;
    }
    int Solve(int n, vector<int>& piles, int h) 
    {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int result = -1;
        
        while (low <= high) 
        {
            int mid = low + (high - low) / 2;
            
            if (isValid(piles, mid, h)) 
            {
                result = mid;
                high = mid - 1;
            } 
            else
                low = mid + 1;
            
        }
        
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int h;
        cin >> h;
        Solution obj;

        cout << obj.Solve(n, a, h);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends