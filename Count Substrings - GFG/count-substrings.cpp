//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	
	int countSubstr (string s)
	{
        int oneCount = 0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='1')
                oneCount++;
        }
        if(oneCount<2)
            return 0;
             
        return ((oneCount)*(oneCount-1))/2;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        
        cout << ob.countSubstr (s) << '\n';
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends