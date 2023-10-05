//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    long long int solve(string &s, int k)
    {
        if(s.size()==0)
            return 0;
            
        vector<int> mp(26,0);
        long long int num=0;
        int i=0;
        int distinct_count=0;
     
        for(int j=0;j<s.size();j++)
        {
            if(mp[s[j]-'a']==0)
                distinct_count++;
                
            mp[s[j]-'a']++;
            
            while(distinct_count>k)
            {
                mp[s[i]-'a']--;
                if(mp[s[i]-'a']==0)
                    distinct_count--;
                i++;
            }
            num+=j-i+1;
        }
        return num;
    }
    
    
    long long int substrCount(string s, int k) 
    {
        // (Atmost k) - (Atmost k-1) = Exactly k
        long long int ans=solve(s,k)-solve(s,k-1);
        return ans;
    }
};

int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}
// } Driver Code Ends