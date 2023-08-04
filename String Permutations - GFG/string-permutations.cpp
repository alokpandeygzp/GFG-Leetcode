//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    void f(int i,string S,vector<string> &ans)
    {
        if(i==S.length())
        {
            ans.push_back(S);
            return;
        }
        
        for(int j=i;j<S.length();j++)
        {
            swap(S[i],S[j]);
            f(i+1,S,ans);
            swap(S[i],S[j]);
        }
    }
    vector<string> permutation(string S)
    {
        vector<string> ans;
        f(0,S,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends