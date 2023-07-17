//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        long long int xorVal=0;
        for(int i=0;i<N;i++)
            xorVal^=Arr[i];
        
        int pos=0;
        while((xorVal & (1<<pos))==0)
            pos++;
        
        int num1=0,num2=0;
        for(int i=0;i<N;i++)
        {
            if(Arr[i] & (1<<pos))
                num1^=Arr[i];
            else
                num2^=Arr[i];
        }
        
        if(num1>num2)
            return {num1, num2};
        else
            return {num2, num1};
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends