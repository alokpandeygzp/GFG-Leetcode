class Solution {
public:
    
    bool isMagic(int row, int col, vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int> count(10, 0);
        
        for(int i=row;i<row+3;i++) {
            for(int j=col;j<col+3;j++) {
                int num = grid[i][j];
                if(num<1 || num>9 || ++count[num] > 1) 
                    return false;
            }
        }
        
        for(int i=row;i<row+3;i++) {
            int colSum=0;
            for(int j=col;j<col+3;j++) {
                colSum+=grid[i][j];
            }
            if(colSum!=15)
                return false;
        }
        
        for(int j=col;j<col+3;j++) {
            int rowSum=0;
            for(int i=row;i<row+3;i++) {
                rowSum+=grid[i][j];
            }
            if(rowSum!=15)
                return false;
        }
        
        int diag1=0, diag2=0;
        for(int i=0;i<3;i++) {
            diag1 += grid[row+i][col+i];
            diag2 += grid[row+2-i][col+i];
        }
        if(diag1!=15 || diag2!=15) 
            return false;
        
        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        int sum=0;
        for(int i=0;i<=n-3;i++) {
            for(int j=0;j<=m-3;j++) {
                if(isMagic(i,j,grid)) {
                    sum++;
                }
            }
        }
        
        return sum;
    }
};