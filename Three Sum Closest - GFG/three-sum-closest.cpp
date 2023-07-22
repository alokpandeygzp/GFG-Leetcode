//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

// arr : given vector of elements
// target : given sum value

class Solution{
  public:
    int threeSumClosest(vector<int>& arr, int x) 
    {
        sort(arr.begin(), arr.end());
        int closestSum=arr[0]+arr[1]+arr[2];
    
        for(int i=0;i<arr.size()-2;i++) 
        {
            int j=i+1,k=arr.size()-1;
    
            while(j<k) 
            {
                int sum=arr[i]+arr[j]+arr[k];
    
                if(abs(sum-x)<abs(closestSum-x))
                    closestSum=sum;
                // Note: If there are multiple solutions, print the maximum one.
                else if(abs(sum-x)==abs(closestSum-x) && sum>closestSum)
                    closestSum=sum;
                    
                if(sum>x)
                    k--;
                else if(sum<x)
                    j++;
                else
                    return x;
            }
        }
        return closestSum;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while(t--) {
        
        int n,target;
        cin >> n >> target;
        
        vector<int> vec(n);
        
        for(int i = 0 ; i < n ; ++ i ) 
            cin >> vec[i];
        Solution obj;
        cout << obj.threeSumClosest(vec, target) << "\n";
    }
}

//Position this line where user code will be pasted.

// } Driver Code Ends