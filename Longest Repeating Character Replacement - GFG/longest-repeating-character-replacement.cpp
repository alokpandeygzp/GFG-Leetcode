//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    int characterReplacement(string s, int k)
    {
        map<char,int> mp; 
        int n=s.size();
        int i=0,j=0;    
        int maxi=0;        // Variable to store the length of the longest substring
        int maxCount=0;    // Variable to store the maximum frequency of any character in the current window

        while(j<n)
        {
            mp[s[j]]++;
            
            // Kisi bhi character ki maximum frequency
            maxCount=max(maxCount, mp[s[j]]);  

            // If the number of characters to be replaced (j-i+1-maxCount) is less than or equal to k,
            // update the maximum length of substring (maxi) and move the window to the right (increment j).
            if(j-i+1-maxCount<=k) 
            {
                maxi=max(maxi,j-i+1);
                j++;
            }
            else
            {
                // If the number of characters to be replaced is greater than k, 
                // move the window to the right (increment both i and j) and remove s[i] from the map.
                mp[s[i]]--;
                i++;
                j++;
            }
        }

        return maxi;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;

        Solution obj;
        cout << obj.characterReplacement(S, K) << endl;
    }
    return 0;
}
// } Driver Code Ends