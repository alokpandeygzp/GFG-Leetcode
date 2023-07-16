//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    bool f(int rows,int cols,int index,vector<vector<char>>& board,string word)
    {
        if(rows<0 || rows>=board.size() || cols<0 || cols>=board[0].size())
            return false;
        
        if(board[rows][cols]!=word[index])
            return false;
        
        if(index==word.size()-1)
            return true;
        
        char ch=board[rows][cols];
        board[rows][cols]='#';
        
        bool found= f(rows-1,cols,index+1,board,word) ||
                    f(rows+1,cols,index+1,board,word) ||
                    f(rows,cols-1,index+1,board,word) ||
                    f(rows,cols+1,index+1,board,word);
        
        board[rows][cols]=ch;
        return found;
    }
    bool wordSearch(vector<vector<char>>& board, string word) {
        int rows=board.size();
        int cols=board[0].size();
        
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(board[i][j]==word[0] && f(i,j,0,board,word))
                    return true;
            }
        }
        return false;
    }

};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<vector<char>> mat(n,vector<char>(m));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>mat[i][j];
            }
        }
        string str; cin>>str;
        Solution ob;
        auto ans=ob.wordSearch(mat,str);
        cout<<ans<<"\n";
    }
    return 0;
}

// } Driver Code Ends