#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%i", &t);
    while (t--)
    {
        int n;
        scanf("%i", &n);
        vector<string> arr(n+1);
        map<string,int> mp;
        for (int x = 1; x <= n; x++)
        {
            cin >> arr[x];
            mp[arr[x]] = x;
        }
        arr[0] = arr.back();
        int dep = 0, ma = 0;
        set<string> st;
        for (int x = 0; x < arr.size(); x++)
        {
            if (!st.count(arr[x]))
                st.insert(arr[x]), dep++;
            ma = max(ma, dep-1);
            if (x == mp[arr[x]])
            {
                st.erase(st.find(arr[x]));
                dep--;
            }
        }
        printf("%i\n", n*10 - ma*20);
    }
}
