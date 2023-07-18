//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    
    string postToPre(string expr) 
    {
        stack<string> s;
        string res="";
        
        for(int i=0;i<expr.size();i++)
        {
            char ch=expr[i];
            
            if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z'))
                s.push(string(1,expr[i]));
            else
            {
                string s1=s.top();
                s.pop();
                string s2=s.top();
                s.pop();
                
                res=expr[i]+s2+s1;
                s.push(res);
            }
        }
        return s.top();
    }
};

//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string postfix;
        cin >> postfix;

        // char marker; cin >> marker;

        Solution obj;
        cout << obj.postToPre(postfix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends