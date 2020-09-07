#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    map<int, string> mp;
    while (n--)
    {
        string s;
        int d;
        cin>>s>>d;
        mp[d] = s;
    }
    int d;
    scanf("%i", &d);
    map<int, int> cnt;
    while (d--)
    {
        int dd;
        scanf("%i", &dd);
        cnt[dd]++;
    }
    int ma_cnt = 0, ma_num = 0;
    for (auto &x : cnt)
    {
        if (x.second > ma_cnt)
            ma_cnt = x.second, ma_num = x.first;
        else if (x.second == ma_cnt)
            ma_num = min(ma_num, x.first);
    }
    printf("%s\n", mp[ma_num].c_str());
}
