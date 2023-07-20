//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countSubarray(int n, vector<int>& nums, int k) {
        int i=0,j=0;
        int maxi=0,count=0;
        
        while(j<n) 
        {
            // If the current element is odd, increment the count.
            if(nums[j]%2==1) 
                count++;

            if(count<k)
                j++;
            else if(count==k)
            {
                int leftCount=0;
                int rightCount=0;

                // Count the number of elements on the left and right side of the current subarray
                // that are even.(Jiski koi value nahi hai)
                while(i<j && nums[i]%2==0)
                {
                    leftCount++;
                    i++;
                }
                
                int temp=j+1;
                while(temp<n && nums[temp]%2==0)
                {
                    rightCount++;
                    temp++;
                }

                maxi+=((leftCount+1)*(rightCount+1));

                // Move the left pointer to the next position to check the next subarray.
                i++;
                // Kyuki i'th element ek odd number tha, jaha hm ruke the
                count--;
                j++;
            } 
            else
            {
                // If the count is greater than 'k', move the left pointer to the next position
                // to reduce the number of odd elements in the subarray.
                if(nums[i]%2!=0)
                    count--;
                i++;
            }
        }
        return maxi;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            nums.push_back(x);
        }

        int k;
        cin >> k;

        Solution obj;
        cout << obj.countSubarray(n, nums, k) << endl;
    }
    return 0;
}
// } Driver Code Ends