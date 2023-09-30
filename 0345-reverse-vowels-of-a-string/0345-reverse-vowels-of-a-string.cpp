class Solution {
public:
    bool isVowel(char c) {
        unordered_set<char> vowels={'a','e','i','o','u'};
        return vowels.count(tolower(c)) > 0;
    }

    string reverseVowels(string s) {
        int left=0;
        int right=s.length()-1;

        while(left<right) {
            while (left<right && !isVowel(s[left]))
                left++;
            while (left<right && !isVowel(s[right]))
                right--;

            if(left<right) {
                swap(s[left],s[right]);
                left++;
                right--;
            }
        }

        return s;
    }
};