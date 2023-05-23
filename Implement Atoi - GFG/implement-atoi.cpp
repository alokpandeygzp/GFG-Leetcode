//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int atoi(string str) 
    {
        int n=str.length();
        int ans=0;
        int flag=0;
        for(int i=0;i<n;i++)
        {
            if(str[i]>=48 && str[i]<=57)
            {
                ans=ans*10+(str[i]-'0');
            }
            else
            {
                if(i==0 && str[i]=='-')
                {
                    flag=1;
                    continue;
                }
                else
                    return -1;
            }
        }
        if(flag==0)
            return ans;
        return -ans;
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