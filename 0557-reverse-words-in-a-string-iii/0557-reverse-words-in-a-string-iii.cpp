class Solution {
public:
    string reverseWords(string str) {
        stack<char> s;
        string ans="";
        int n=str.length();
        for(int i=0;i<n;i++)
        {
            if(str[i]==32)
            {
                while(!s.empty())
                {
                    ans+=s.top();
                    s.pop();
                }
                ans+=" ";
            }
            else
                s.push(str[i]);
        }
        while(!s.empty())
        {
            ans+=s.top();
            s.pop();
        }
        return ans;
    }
};