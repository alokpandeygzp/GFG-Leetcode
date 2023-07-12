//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b)
    {
        if(a.size()!=b.size())
            return false;
            
        map<char, int> mp;
        for(int i=0;i<a.size();i++)
            mp[a[i]]++;
        
        for(int i=0;i<b.size();i++)
        {
            if(mp.find(b[i])!=mp.end())
            {
                mp[b[i]]--;
                if(mp[b[i]]==0)
                    mp.erase(b[i]);
            }
            else
                return false;
            
        }
        return true;
    }

};

//{ Driver Code Starts.

int main() {
    
    int t;

    cin >> t;

    while(t--){
        string c, d;

        cin >> c >> d;
        Solution obj;
        if(obj.isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}

// } Driver Code Ends