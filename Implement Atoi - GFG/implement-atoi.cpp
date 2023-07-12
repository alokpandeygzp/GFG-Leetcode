//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) 
    {
        int flagNeg=0,ans=0;
        for(int i=0;i<str.size();i++)
        {
            if(str[i]>=48 && str[i]<=57)
            {
                ans=ans*10+(str[i]-'0');
            }
            else if(str[0]=='-')
            {
                str[0]='@';
                flagNeg=1;
            }
            else
                return -1;
        }
        return (flagNeg==1)?(-ans):ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends