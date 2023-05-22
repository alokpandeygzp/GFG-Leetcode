//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string maxOdd(string s) 
    {
        for(int i=s.length()-1;i>=0;i--)
        {
            string temp=s.substr(i,1);
            if(stoi(temp)%2!=0)
                return s.substr(0,i+1);
        }
        return "";
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;

        cout << ob.maxOdd(s) << endl;
    }
}

// } Driver Code Ends