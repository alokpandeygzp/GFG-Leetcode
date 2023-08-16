//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int i,vector<int> adj[], int V, vector<int> &vis,vector<int> &pathVis)
    {
        vis[i]=1;
        pathVis[i]=1;
        
        for(auto it:adj[i])
        {
            if(!vis[it])
            {
                if(dfs(it,adj,V,vis,pathVis)==true)
                    return true;
            }
            else if (pathVis[it]) 
                return true; 
        }
        pathVis[i]=0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[])
    {
        vector<int> vis(V,0);
        vector<int> pathVis(V,0);
        
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(dfs(i,adj,V,vis,pathVis)==true)
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