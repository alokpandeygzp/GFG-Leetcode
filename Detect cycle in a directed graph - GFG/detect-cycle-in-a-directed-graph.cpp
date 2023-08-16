//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int i,vector<int> adj[],vector<int> &vis)
    {
        vis[i]=2;
        
        for(auto it:adj[i])
        {
            if(vis[it]==0)
            {
                if(dfs(it,adj,vis)==true)
                    return true;
            }
            else if(vis[it]==2) 
                return true; 
        }
        vis[i]=1;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[])
    {
        vector<int> vis(V,0);
        
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(dfs(i,adj,vis)==true)
                    return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends