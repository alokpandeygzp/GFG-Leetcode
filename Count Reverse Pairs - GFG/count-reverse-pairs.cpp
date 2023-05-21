//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int merge(vector<int> &arr, int left, int mid, int right){
        int cnt = 0;
        int j = mid+1;
        
        for(int i=left;i<=mid;i++){
            while(j <= right && arr[i] > 2* arr[j]) j++;
            cnt += j - (mid+1);
        }
        
        vector<int> temp;
        int i = left;
        j = mid+1;
        while(i <= mid && j <= right){
            if(arr[i] <= arr[j]) temp.push_back(arr[i++]);
            else temp.push_back(arr[j++]);
        }
        
        while(i <= mid) temp.push_back(arr[i++]);
        while(j <= right) temp.push_back(arr[j++]);
        
        for(int i=left;i<=right;i++) arr[i] = temp[i - left];
        
        return cnt;
    }
  
    int mergeSort(vector<int> &arr, int left, int right){
        if(left >= right) return 0;
        
        int cnt = 0;
        int mid = (left + right) / 2;
        cnt += mergeSort(arr, left, mid);
        cnt += mergeSort(arr, mid+1, right);
        cnt += merge(arr, left, mid, right);
        return cnt;
    }
  
    int countRevPairs(int n, vector<int> arr) {
        return mergeSort(arr, 0, n-1);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countRevPairs(n, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends