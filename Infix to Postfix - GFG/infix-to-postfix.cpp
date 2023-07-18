//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string s) 
    {
        stack<char> st;
        string ans="";
        map<char,int> mp={{'+',1},{'-',1},{'*',2},{'/',2},{'^',3}};
    
        for(char ch:s)
        {
            if(ch=='(')
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
            else if(mp.find(ch)!=mp.end())
            {
                while(!st.empty() && st.top()!='(' && mp[ch]<=mp[st.top()])
                {
                    ans+=st.top();
                    st.pop();
                }
                st.push(ch);
            } 
            else
                ans+=ch;
        }
    
        while (!st.empty()) 
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