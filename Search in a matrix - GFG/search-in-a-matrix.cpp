//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int matSearch (vector <vector <int>> &mat, int row, int col, int elt)
	{
	    //Aap ko first row ko last se traverse krna hai. Since matrix row/col is sorted 
	    //Aapko jese pta lge ki ab element target se kam milne suru ho gye
	    //to niche row par chle jao sidha. Or jis column se aapne pichli row ko chhoda hai
	    //usi se traverse krna hai agli ko left ki side. same kam jab tak element nhi 
	    //milta or milta to 1 return vrna 0.
	    
	    int i=0, j=col-1;
	    while(i<row && j>=0)
	    {
	        if(mat[i][j]==elt)
	            return 1;
	        else if(mat[i][j]<elt)
	            i++;
	        else
	            j--;
	    }
	    return 0;
	}
};

//{ Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        vector <vector <int>> arr (n, vector <int> (m));
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                cin >> arr[i][j];
                
        int x; cin >> x;
        Solution ob;
        cout << ob.matSearch (arr, n, m, x) << endl;
    }
}
// } Driver Code Ends