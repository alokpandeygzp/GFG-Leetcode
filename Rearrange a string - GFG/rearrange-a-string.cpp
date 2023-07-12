//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
  public:
    string arrangeString(string str)
    {
        vector<int> freq(26,0);
        long long sum=0;
        for(int i=0;i<str.size();i++)
        {
            if(!isdigit(str[i]))
                freq[str[i]-'A']++;
            else
                sum+=(str[i]-'0');
                
        }
        
        string ans="";
        for(int i=0;i<26;i++)
        {
            while(freq[i]--)
                ans+=(i+'A');
        }
        
        if(sum!=0)
            return ans+to_string(sum);

        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout <<ob.arrangeString(s) << endl;
    }
return 0;
}


// } Driver Code Ends