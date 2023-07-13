#include<iostream>
#include<queue>

using namespace std;

string findNthGood(int n)
{
    queue<string> q;
    q.push("1");
    q.push("2");

    string nthGoodNumber;
    for (int i=1;i<=n; i++)
    {
        nthGoodNumber = q.front();
        q.pop();

        q.push(nthGoodNumber + "1");
        q.push(nthGoodNumber + "2");
    }

    return nthGoodNumber;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        cout<<findNthGood(n)<<endl;
    }
    return 0;
}