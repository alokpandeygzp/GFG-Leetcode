//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string s) 
    { 
        s+=".";
        stack<string> st;
        int i;
        string str="";
        for(i=0;i<s.length();i++)
        {
            if(s[i]=='.')
            {
                st.push(str);
                str="";
            }
            else str+=s[i];
        }
        string ans="";
        while(st.size()!=1)
        {
            ans+=st.top()+".";
            st.pop();
        }
        ans+=st.top();// The last word should'nt have a space after it
        return ans;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends