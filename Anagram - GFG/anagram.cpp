//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
    const int CHAR=256;
    bool isAnagram(string a, string b){
        
        if(a.length()!=b.length())
            return false;
            
        map<char,int> mp;
        
        for(int i=0;i<a.length();i++)
            mp[a[i]]++;
        
        // for(auto it:mp)
        //     cout<<it.first<<it.second<<", ";
        
        // cout<<endl<<endl;
        for(int i=0;i<b.length();i++)
        {
            // cout<<b[i]<<mp[b[i]]<<", ";
            if(mp.find(b[i])==mp.end())
                return false;
            else
                mp[b[i]]--;
        }
        
        for(auto it:mp)
            if(it.second==0)
                mp.erase(it.first);
        
        if(mp.size()!=0)
            return false;
            
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