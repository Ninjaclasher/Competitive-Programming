#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i", &n);
    set<string> chk;
    vector<int> arr(6);
    while (n--)
    {
        for (auto &x : arr)
            scanf("%i", &x);
        string mi = "";
        for (int x = 0; x < 6; x++)
        {
            string cur = "";
            for (int y = 0; y < 6; y++)
                cur += to_string(arr[(x+y)%6]) + " ";
            if (mi == "" || cur < mi)
                mi = cur;
        }
        reverse(arr.begin(), arr.end());
        for (int x = 0; x < 6; x++)
        {
            string cur = "";
            for (int y = 0; y < 6; y++)
                cur += to_string(arr[(x+y)%6]) + " ";
            if (mi == "" || cur < mi)
                mi = cur;
        }
        if (chk.find(mi) != chk.end())
            return 0 * printf("Twin snowflakes found.\n"); 
        chk.insert(mi);
    }
    printf("No two snowflakes are alike.\n");
}
