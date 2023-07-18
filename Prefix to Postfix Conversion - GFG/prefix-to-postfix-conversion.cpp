//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string preToInfix(string exp)
    {
        stack<string> st;
        for(int i=exp.size()-1;i>=0;i--)
        {
            char ch=exp[i];
            
            if(isalnum(ch)){
                string operand(1, ch);
                st.push(operand);
            }

            else if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^')
            {
                string s1=st.top();
                st.pop();

                string s2=st.top();
                st.pop();
                
                string s3="("+s1+ch+s2+")";
                st.push(s3);
            }
        }
        return st.top();
    }
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
    string preToPost(string pre_exp) {
        string temp=preToInfix(pre_exp);
        return infixToPostfix(temp);
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToPost(prefix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends