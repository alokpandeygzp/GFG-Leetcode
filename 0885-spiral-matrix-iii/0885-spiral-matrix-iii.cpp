class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart)     {
        vector<vector<int>> ans;
        
        int count=0;
        int numCount=0;
        int i=rStart, j=cStart;
        
        ans.push_back({i, j});
        numCount++;
        
        while(numCount<rows*cols) {
            
            count++;
            
            //Move right
            for(int step=0;step<count;step++) {
                j++;
                if(i>=0 && i<rows && j>=0 && j<cols) {
                    ans.push_back({i, j});
                    numCount++;
                }
            }
                
            //Move down
            for(int step=0;step<count;step++) {
                i++;
                if(i>=0 && i<rows && j>=0 && j<cols) {
                    ans.push_back({i, j});
                    numCount++;
                }
            }  
            
            count++;
            
            //Move left
            for(int step=0;step<count;step++) {
                j--;
                if(i>=0 && i<rows && j>=0 && j<cols) {
                    ans.push_back({i, j});
                    numCount++;
                }
            }
                
            //Move up
            for(int step=0;step<count;step++) {
                i--;
                if(i>=0 && i<rows && j>=0 && j<cols) {
                    ans.push_back({i, j});
                    numCount++;
                }
            }  
        }
        
        return ans;
    }
};