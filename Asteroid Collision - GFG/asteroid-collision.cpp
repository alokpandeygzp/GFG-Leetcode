//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> asteroidCollision(int N, vector<int> &asteroids) 
    {
        stack<int> s;
        
        for(int val:asteroids) 
        {
            if(val>0)
                s.push(val);
            else
            {
                while(s.size()>0 && s.top()>0 && s.top()<-val)
                    s.pop();
                
                if(s.size()>0 && s.top()==-val)
                    s.pop();
                else if (s.size()>0 && s.top()>-val)
                    continue;
                else
                    s.push(val);
            }
        }
        
        vector<int> ans;
        while(!s.empty()) 
        {
            ans.push_back(s.top());
            s.pop();
        }
        
        reverse(ans.begin(), ans.end());
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

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends