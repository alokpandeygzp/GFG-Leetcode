//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    int setBit(int N)
    {
        int temp=N;
        int i=0;
        while(temp>0)
        {
            int lastBit=temp%2;
            if(lastBit==0)
                break;
            temp=temp>>1;
            i++;
        }
        
        return (temp==0)?N:N+pow(2,i);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        Solution ob;
        int ans = ob.setBit(N);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends