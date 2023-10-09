class Solution {
public:
    int maxArea(vector<int>& arr) {
        int n=arr.size();
        
        int low=0, high=n-1;
        int maxi=0;
        while(low<=high)
        {
            int water=min(arr[low],arr[high])*(high-low);
            maxi=max(maxi,water);
            if(arr[low]<arr[high])
                low++;
            else
                high--;
        }
        return maxi;
        
    }
};