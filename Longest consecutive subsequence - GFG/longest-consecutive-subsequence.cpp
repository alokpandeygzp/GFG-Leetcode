//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
        set<int> s;
        for(int i=0;i<N;i++)
            s.insert(arr[i]);
        
        //Stored in ordered way
        int count=0,maxi=0,f=0,i=0;
        while(i<N)
        {
            if(s.find(arr[i]-1)!=s.end())
                i++;
            
            //First elt khoj ke baaki trace kr lenge
            else if(s.find(count+arr[i])!=s.end())
            {
                count++;
                maxi=max(maxi,count);
                f++;
            }
            else
            {
                i++;
                count=0;
                f=0;
            }
        }
        return maxi;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends