//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

vector<string>  spaceString(char str[]);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        char str[10000];
        cin>>str;
        vector<string> vec = spaceString(str);
        for(string s: vec){
            cout<<s<<"$";
        }
        cout<<endl;
    }

}

// } Driver Code Ends


/*You have to complete this function*/

void f(int i, int n, string str, vector<string>&ans, string temp)
{
    if(i>=n){
        ans.push_back(temp);
        return;
    }
    temp.push_back(str[i]);
    
    f(i+1, n, str, ans, temp);
    
    if(i!=n-1)
    {
        temp.push_back(' ');
        f(i+1,n,str, ans, temp);
    }
}
vector<string>  spaceString(char str[])
{
    vector<string>ans;
    string temp;
    string s(str);
    f(0,s.size(),s,ans,temp);
    return ans ;
}