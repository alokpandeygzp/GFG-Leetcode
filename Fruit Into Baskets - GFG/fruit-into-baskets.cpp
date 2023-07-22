//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int totalFruits(int N, vector<int> &fruits) 
    {
        int i=0,j=0;
        int n=fruits.size();
        map<int,int> mp;
        int ans=INT_MIN;
        
        while(j<n)
        {
            mp[fruits[j]]++;
            if(mp.size()<=2)
            {
                ans=max(ans,j-i+1);
                j++;
            }
            else
            {
                while(mp.size()>2)
                {
                    mp[fruits[i]]--;
                    if(mp[fruits[i]]==0)
                        mp.erase(fruits[i]);
                    i++;
                }
                if(mp.size()==2)
                    ans=max(ans,j-i+1);
                j++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> fruits(N);
        for (int i = 0; i < N; i++) cin >> fruits[i];
        Solution obj;
        cout << obj.totalFruits(N, fruits) << endl;
    }
    return 0;
}

// } Driver Code Ends