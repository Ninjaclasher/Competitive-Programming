#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    long long arr[4] = {0, 0, 0, 0};
    for (auto &x : s)
    {
        if (x == 'e')
            arr[3]++;
        else if (x == 'v')
            arr[2] += arr[3];
        else if (x == 'o')
            arr[1] += arr[2];
        else if (x == 'l')
            arr[0] += arr[1];
    }
    cout<<arr[0]<<endl;
}
