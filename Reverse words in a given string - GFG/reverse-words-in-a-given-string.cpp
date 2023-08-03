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
        string str="";
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='.')
            {
                st.push(str);
                str="";
            }
            else
                str+=s[i];
        }
        
        string ans="";
        while(st.size()!=1)
        {
            ans+=st.top()+".";
            st.pop();
        }
        
        //Last word
        ans+=st.top();
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