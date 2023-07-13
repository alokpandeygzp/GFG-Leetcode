//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void f(int num,string temp, vector<string> &ans)
    {
        if(num<=0) {
            ans.push_back(temp);
            return; 
        }  
        
        f(num-1,temp+"0",ans);
        
        if(temp.back()!='1')
            f(num-1,temp+"1",ans);
    }
    void generateBinaryStrings(int num){
        vector<string> ans;
        f(num,"",ans);
        
        for(int i=0;i<ans.size();i++)
            cout<<ans[i]<<" ";
    }
};

//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;


    while(t--){
        //Input
        int n; cin >> n;

        Solution obj;
        obj.generateBinaryStrings(n);
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends