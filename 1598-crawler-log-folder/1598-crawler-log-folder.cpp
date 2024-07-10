class Solution {
public:
    int minOperations(vector<string>& logs) {
        int rootDist=0;
        for(string log: logs) {
            if(log[0]=='.' && log[1]=='.') {
                if(rootDist==0) rootDist=0;
                else    rootDist--;
            }
            else if(log[0]=='.' && log[1]=='/') {
                continue;
            }
            else
                rootDist++;
        }
        return rootDist;
    }
};