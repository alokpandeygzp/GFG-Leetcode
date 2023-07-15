//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find the minimum indexed character.
    int minIndexChar(string str, string patt)
    {
        map<char,int> mp;
        for(int i=0;i<patt.size();i++)
            mp[patt[i]]++;
            
        int index=INT_MAX;
        for(int i=0;i<str.size();i++)
        {
            if(mp.find(str[i])!=mp.end())
            {
                index=min(index,i);
            }
        }
        if(index!=INT_MAX)
            return index;
        return -1;
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
        string patt;
        cin>>str;
        cin>>patt;
        Solution obj;
        cout<<obj.minIndexChar(str, patt)<<endl;
    }
	return 0;
}

// } Driver Code Ends