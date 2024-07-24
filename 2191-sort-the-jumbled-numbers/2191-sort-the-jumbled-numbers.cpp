class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int, int>> mapped_nums;

        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            string str = "";
            if (num == 0) { 
                str = to_string(mapping[0]);
            } else {
                while (num > 0) {
                    int lastDigit = num % 10;
                    int mappedDigit = mapping[lastDigit];
                    str = to_string(mappedDigit) + str;
                    num = num / 10;
                }
            }
            mapped_nums.push_back({stoi(str), i});
        }

        sort(mapped_nums.begin(), mapped_nums.end());

        vector<int> ans;
        for (auto pair : mapped_nums) {
            ans.push_back(nums[pair.second]);
        }
        return ans;
    }
};