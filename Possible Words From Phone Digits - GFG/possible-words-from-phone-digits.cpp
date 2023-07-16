//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find list of all words possible by pressing given numbers.
    vector<string> keypad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void f(int index, string digits, string str, vector<string>& ans) {
        if(index==digits.length())
        {
            ans.push_back(str);
            return;
        }
    
        int n=digits[index]-'0';
        string letters=keypad[n];
    
        for(char c:letters)
            f(index+1,digits,str+c,ans);
    }
    
    vector<string> possibleWords(int a[], int N) 
    {
        string digits="";
        for(int i=0;i<N;i++)
            digits+=to_string(a[i]);
    
        vector<string> ans;
        f(0,digits,"",ans);
    
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}
// } Driver Code Ends