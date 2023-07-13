//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
    
    void f(string& str, int index, unordered_set<string>& result)
    {
        if(index==str.length()) {
            result.insert(str);
            return;
        }
    
        if(str[index]=='?')
        {
            str[index]='0';
            f(str,index+1,result);
    
            str[index]='1';
            f(str,index+1,result);
    
            // Reset the character back to '?' to explore other possibilities
            str[index]='?';
        }
        else
            f(str,index+1,result);
    }
    
    vector<string> generate_binary_string(string str) 
    {
        unordered_set<string> set;
        f(str, 0, set);
    
        vector<string> res(set.begin(), set.end());
        sort(res.begin(), res.end());
    
        return res;
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
	    string s;
	    cin >> s;
	    Solution ob;
	    vector<string> ans = ob.generate_binary_string(s);
	    for(auto i: ans)
	    	cout << i << " ";
	    cout << "\n";
    }
	return 0;
}
// } Driver Code Ends