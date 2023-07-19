//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int longestUniqueSubsttr(string s)
    {
        int n=s.length();
        int ans=0;
        vector<int> lastIndex(256,-1); 
        
        int i=0;
        for(int j=0;j<n;j++)
        {
            i=max(i,lastIndex[s[j]]+1); // Update the starting index of the current substring
            ans=max(ans, j-i+1); // Update the maximum length
            lastIndex[s[j]]=j; // Update the last index of the current character
        }
        
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
		string str;
		cin>>str;
		Solution ob;
		cout<<ob.longestUniqueSubsttr(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends