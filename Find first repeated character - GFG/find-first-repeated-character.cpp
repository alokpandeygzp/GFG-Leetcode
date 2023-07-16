//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string firstRepChar(string s);
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        cout<<firstRepChar(s)<<endl;
    }
	return 0;
}
// } Driver Code Ends


string firstRepChar(string s)
{
    map<char,int> mp;
    string ans="";
    for(int i=0;i<s.size();i++)
    {
        if(mp.find(s[i])==mp.end())
            mp[s[i]]++;
        else{
            ans+=s[i];
            break;
        }
    }
    if(ans=="")
        return "-1";
    return ans;
}