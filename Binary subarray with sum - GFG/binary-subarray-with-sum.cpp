//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    int numberOfSubarrays(vector<int>& nums, int N, int goal){
        unordered_map<int,int> prefixSumCounts;
        int sum=0; 
        int ans=0;

        for(int num : nums)
        {
            sum+=num; 
            if(sum==goal)
                ans++; 

            if(prefixSumCounts.find(sum-goal) != prefixSumCounts.end())
            {
                /*Check if there exists a prefix sum (sum of a subarray starting from 
                index 0 and ending at some index 'i') such that 'prefixSum - goal' 
                is equal to the current 'sum'. If yes, it means there is a subarray 
                between the two indices with a sum equal to 'goal'. 
                Add the count of occurrences of this prefix sum to 'ans'.*/
                ans+=prefixSumCounts[sum-goal];
            }
            
            prefixSumCounts[sum]++; // Increment the count of the current 'sum' in the 'prefixSumCounts' map.
        }

        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int target; 
        cin >> target;
        vector<int> arr(N);
        for(int i=0; i<N; i++)
            cin >> arr[i];
        Solution obj;
        cout<<obj.numberOfSubarrays(arr, N, target)<<endl;
    }
    return 0;
}
// } Driver Code Ends