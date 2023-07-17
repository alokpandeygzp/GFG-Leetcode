//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    int f(string A, vector<string> &B, int i, int j)
    {
        if(i>j)
            return 1;
    
        for(int k=i;k<=j;k++)
        {
            if(find(B.begin(),B.end(),A.substr(i,k-i+1)) != B.end() && f(A,B,k+1,j))
                return 1;
        }
        return 0;
    }
    int wordBreak(string A, vector<string> &B)
    {
        int n=A.size();
        return f(A,B,0,n-1);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends