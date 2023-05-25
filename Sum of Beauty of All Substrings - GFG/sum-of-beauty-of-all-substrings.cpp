//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int beauty(vector<int> &freq)
    {
        int mini=INT_MAX;
        int maxi=INT_MIN;
        
        for(int i=0;i<26;i++)
        {
            if(freq[i]!=0)
            {
                mini=min(mini,freq[i]);
                maxi=max(maxi,freq[i]);
            }
        }
        return (maxi-mini);
    }
    int beautySum(string s) 
    {
        int sum=0, n=s.size();
        
        for(int i=0;i<n;i++)
        {
            vector<int> freq(26,0);
            
            for(int j=i;j<n;j++)
            {
                // a=0, b=1, c=2 ... and so on
                freq[s[j]-'a']++;
                sum += beauty(freq);
            }
        }
        return sum;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.beautySum(s) << endl;
    }
    return 0;
}
// } Driver Code Ends