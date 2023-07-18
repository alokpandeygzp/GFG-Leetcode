//{ Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
	public:
	vector<int> AllPrimeFactors(int N) {
    	vector<int> ans;
    
        while(N%2==0)
        {
            ans.push_back(2);
            N=N/2;
        }
    
        for(int i=3;i<=sqrt(N); i+=2)
        {
            while(N%i==0)
            {
                ans.push_back(i);
                N=N/i;
            }
        }
    
        if(N>2)     ans.push_back(N);

        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		long long int N;
		cin >> N;
		Solution ob;
		vector<int>ans = ob.AllPrimeFactors(N);
		for(auto i: ans)
			cout << i <<" ";
		cout <<"\n";
	}  
	return 0;
}
// } Driver Code Ends