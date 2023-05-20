//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int>> fourSum(vector<int> &arr, int key) {
        vector<vector<int>> ans;
        set<vector<int>> st;
        sort(arr.begin(),arr.end());
        int n=arr.size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n-1;j++)
            {
                int k=j+1,l=n-1;
                while(k<l)
                {
                    int sum=arr[i]+arr[j]+arr[k]+arr[l];
                    if(sum==key)
                    {
                        vector<int>temp;
                        temp.push_back(arr[i]);
                        temp.push_back(arr[j]);
                        temp.push_back(arr[k]);
                        temp.push_back(arr[l]);
                        st.insert(temp);
                    
                        k++;
                        l--;
                    }
                    else if(sum>key)
                        l--;
                    else if(sum<key)
                        k++;
                }
            }
        }
        for(auto i:st) 
            ans.push_back(i);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends