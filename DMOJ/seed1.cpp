#include <bits/stdc++.h>

using namespace std;

int main()
{
    map<char,int> mp;
    for (auto x : "BFTLC")
        mp[x]++;
    mp['\0'] = 0; 
    string s;
    cin>>s;
    for (auto &x : s)
        mp[x]--;
    bool d = false;
    for (auto &x : mp)
        if (x.second > 0)
            printf("%c", x.first), d = true;
    if (!d)
        printf("NO MISSING PARTS\n");
}
