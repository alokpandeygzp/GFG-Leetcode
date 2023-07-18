//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    int checkPref(char ch1, char ch2)
    {
        map<char,int> mp;
        mp['+']=1;
        mp['-']=1;
        mp['*']=2;
        mp['/']=2;
        mp['^']=3;
        
        if(mp[ch1]==mp[ch2])        return 0;
        else if(mp[ch1]>mp[ch2])    return 1;
        else if(mp[ch1]<mp[ch2])    return -1;
    }
    string infixToPostfix(string s) 
    {
        stack<char> st;
        string ans="";
        
        for(int i=0;i<s.size();i++)
        {
            char ch=s[i];
            
            //Operators
            if(ch=='*' || ch=='/' || ch=='+' || ch=='-' || ch=='^')
            {
                if(st.empty())
                    st.push(ch);
                else
                {
                    if(checkPref(ch,st.top())==1)
                        st.push(ch);
                    else
                    {
                        while(!st.empty() && (checkPref(ch,st.top())==-1 || checkPref(ch,st.top())==0))
                        {
                            ans+=st.top();
                            st.pop();
                        }
                        st.push(ch);
                    }
                }
            }
            
            else if(ch=='(')
                st.push(ch);
            else if(ch==')')
            {
                while(!st.empty() && st.top()!='(')
                {
                    ans+=st.top();
                    st.pop();
                }
                st.pop();
            }
            else
                ans+=ch;
        }
        
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};


//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends