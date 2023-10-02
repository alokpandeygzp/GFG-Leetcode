class Solution {
public:
    bool winnerOfGame(string colors) {
        int countA=0, countB=0;
        int n=colors.size();

        for(int i=0;i<n-2;i++) 
        {
            if(colors[i]==colors[i+1] && colors[i]==colors[i+2]) 
            {
                if(colors[i]=='A')
                    countA++;
                else
                    countB++;
            }
        }

        return countA>countB;
    }
};