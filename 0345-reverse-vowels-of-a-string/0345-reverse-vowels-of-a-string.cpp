class Solution {
public:
    string reverseVowels(string s) {
        map<int,char> mp;
        string vowel="aeiouAEIOU";
        
        for(int i=0,j=s.length()-1;i<j;i++,j--)
        {
            while(i<j && vowel.find(s[i]) == string::npos) i++;
            while(i<j && vowel.find(s[j]) == string::npos) j--;
            
            if(i<j)
            {
                swap(s[i],s[j]);
            }
        }      
        return s;
    }
};