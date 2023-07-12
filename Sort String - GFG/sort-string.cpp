#include <iostream>
#include <algorithm>

using namespace std;

string sortString(string s) {
    sort(s.begin(), s.end());
    return s;
}
int main()
 {
	int T;
    cin>>T;

    for(int i=0;i<T;i++)
    {
        string s;
        cin >> s;
        string sortedString = sortString(s);
        cout << sortedString << endl;
    }

    return 0;
}