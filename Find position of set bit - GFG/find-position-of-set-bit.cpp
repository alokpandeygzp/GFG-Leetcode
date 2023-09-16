//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int findPosition(int num) {
        int ans=1,count=0;
        int N=num;
        while(N>0)
        {
            if(N%2!=0){
                break;
            }
             
            ans++;
            N=N>>1;
        }
        N=num;
        while(N>0)
        {
            if(N%2!=0){
                count++;
            }
            N=N>>1;
        }
        
        if(count==1)
            return ans;
        
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;

        cin>>N;

        Solution ob;
        cout << ob.findPosition(N) << endl;
    }
    return 0;
}
// } Driver Code Ends