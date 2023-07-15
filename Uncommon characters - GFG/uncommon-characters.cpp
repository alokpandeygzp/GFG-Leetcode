//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
        string UncommonChars(string A, string B)
        {
            string ans="";
            unordered_map<char, int> mp1,mp2;
            
            for(int i=0;i<A.length();i++)
                mp1[A[i]]=1;
            
            for(int i=0;i<B.length();i++)
                mp2[B[i]]=1;
            
            for(char ch='a';ch<='z';ch++)
            {
                if(mp1[ch]!=mp2[ch])
                    ans.push_back(ch);
            }
            
            if(ans.empty())
                return "-1";
            
            sort(ans.begin(), ans.end());
            return ans;
        }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string A,B;
        cin>>A;
        cin>>B;
        Solution ob;
        cout<<ob.UncommonChars(A, B);
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends