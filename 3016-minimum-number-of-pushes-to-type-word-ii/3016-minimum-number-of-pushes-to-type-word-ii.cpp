class Solution {
public:
    int minimumPushes(string word) {
        
        vector<int> mp(26,0);
        for(int i=0;i<word.length();i++) {
            mp[word[i]-'a']++;
        }
        
        sort(mp.begin(), mp.end(), greater<int>());
        
        int count=0;
        for(int i=0;i<26;i++) {
            if(mp[i]!=0)
                count+=((i/8)+1)*mp[i];
        }
        
        return count;
    }
};