//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    map<char,int> mp;
		    string str="";
		    int i=0;
		    
		    for(int j=0;j<A.size();j++)
		    {
		        mp[A[j]]++;
		        if(mp[A[j]]>=2)
		        {
		            while(i<=j && mp[A[i]]>=2)
                        i++;

                    if(i>j) 
                        str+="#";
                    else 
                        str+=A[i];
		        }
		        else
		            str+=A[i];
		    }
		    return str;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends