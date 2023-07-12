//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countSubstring(string s) {
        int countA=0, countB=0, countC=0;
        int ans=0;
        int n=s.size();
    
        int i=0, j=0;
        while(j<n) 
        {
            if(s[j]=='a')
                countA++;
            if(s[j]=='b')
                countB++;
            if(s[j]=='c')
                countC++;
    
            while(countA>0 && countB>0 && countC>0)
            {
                ans+=n-j;  
                if(s[i]=='a')
                    countA--;
                if(s[i]=='b')
                    countB--;
                if(s[i]=='c')
                    countC--;
                i++;
            }
    
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
        string s;
        cin >> s;

        Solution obj;
        cout << obj.countSubstring(s) << endl;
    }
    return 0;
}
// } Driver Code Ends