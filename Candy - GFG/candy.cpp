//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minCandy(int N, vector<int> &ratings) {
        vector<int> left(N,1);
        vector<int> right(N,1);
        
        for(int i=0;i<N-1;i++)
            if(ratings[i]<ratings[i+1])
                left[i+1]=left[i]+1;
                
        for(int i=N-1;i>0;i--)
            if(ratings[i-1]>ratings[i])
                right[i-1]=right[i]+1;
            
        vector<int> ans(N);    
        for(int i=0;i<N;i++)
            ans[i]=max(left[i],right[i]);
        
        
        return accumulate(ans.begin(),ans.end(),0);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> ratings(N);
        for (int i = 0; i < N; i++) {
            cin >> ratings[i];
        }
        Solution obj;
        cout << obj.minCandy(N, ratings) << endl;
    }
    return 0;
}
// } Driver Code Ends