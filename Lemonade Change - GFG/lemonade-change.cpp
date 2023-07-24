//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool lemonadeChange(int N, vector<int> &bills) {
        int five=0, ten=0, twenty=0;
        for(int i=0;i<N;i++)
        {
            if(bills[i]==5)
                five++;
            else if(bills[i]==10)
            {
                if(five>0)
                    five--;
                else
                    return false;
                ten++;
            }
            else if(bills[i]==20)
            {
                twenty++;
                int sum=0;
                if(ten>0)   
                {
                    sum+=10;
                    ten--;
                }
                while(five>0 && sum!=15)   
                {
                    sum+=5;
                    five--;
                }
                if(sum!=15) return false;
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> bills(N);
        for (int i = 0; i < N; i++) cin >> bills[i];

        Solution obj;
        int ans = obj.lemonadeChange(N, bills);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends