//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int countSubstring(string S)
    {
        int count=0;

        for(int i=0;i<S.length()-1;i++) 
        {
            int lowerCase=0, upperCase=0;
    
            for(int j=i;j<S.length();j++) 
            {
                if(islower(S[j]))
                    lowerCase++;
                else
                    upperCase++;
    
                if(lowerCase==upperCase)
                    count++;
            }
        }
    
        return count;
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
        cout<<obj.countSubstring(S)<<endl;
    }
}  
// } Driver Code Ends