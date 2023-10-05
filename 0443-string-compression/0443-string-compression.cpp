class Solution {
public:
    int compress(vector<char>& chars) 
    {
        char curr=chars[0];
        int count=1;
        string s;
        
        for(int i=1;i<=chars.size();i++) 
        {
            if(i<chars.size() && chars[i]==curr)
                count++;
            else
            {
                s.push_back(curr);
                if(count>1) 
                    s+=to_string(count);
                
                curr=(i<chars.size())?chars[i]:0;
                count=1;
            }
        }
        
        for(int i=0;i<s.size();i++)
            chars[i]=s[i];
        
        return s.size();
    }
};