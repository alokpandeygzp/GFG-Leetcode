class Solution {
public:
    
    int isMagic(int row, int col, vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        map<int,int> mp;
        
        for(int i=row-1;i<row+2;i++) {
            int colSum=0;
            for(int j=col-1;j<col+2;j++) {
                if(i>=0 && i<n && j>=0 && j<m) {
                    mp[grid[i][j]]++;
                    colSum+=grid[i][j];
                }
            }
            // cout<<"colSum:"<<colSum<<",";
            if(colSum!=15) {
                return 0;
            }
        }
        
        for(int j=col-1;j<col+2;j++) {
            int rowSum=0;
            for(int i=row-1;i<row+2;i++) {
                if(i>=0 && i<n && j>=0 && j<m) {
                    rowSum+=grid[i][j];
                }
            }
            // cout<<"rowSum:"<<rowSum<<",";
            if(rowSum!=15) {
                return 0;
            }
        }
        
        for(auto num: mp) {
            if((num.first>9 || num.first<1) || mp.size()!=9) {
                return 0;
            }
        }
        
        return 1;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        int sum=0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j]==5) {
                    sum+=isMagic(i,j,grid);
                }
            }
        }
        
        return sum;
    }
};