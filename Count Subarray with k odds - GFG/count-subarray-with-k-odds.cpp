//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countSubarray(int n, vector<int>& nums, int k) {
        int i=0,j=0,maxi=0,count=0;
        
        while(j<n) 
        {
            // If the current element is odd, increment the count.
            if(nums[j]%2==1) 
                count++;

            if(count<k)
                j++;
            else if(count==k)
            {
                int leftCount=1;
                int rightCount=1;

                // Count the number of elements on the left side of the current subarray
                // that are also odd.
                while(i<j && nums[i]%2==0)
                {
                    leftCount++;
                    i++;
                }

                // Count the number of elements on the right side of the current subarray
                // that are also odd.
                int temp=j+1;
                while(temp<n && nums[temp]%2==0)
                {
                    rightCount++;
                    temp++;
                }

                // Update the 'maxi' variable by adding the product of leftCount and rightCount.
                maxi+=(leftCount*rightCount);

                // Move the left pointer to the next position to check the next subarray.
                i++;
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