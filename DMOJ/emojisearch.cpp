#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    getline(cin, s);
    assert(1 <= s.size() && s.size() <= 2000);
    string cur = "";
    bool ru = false;
    for (int x = 0; x < s.size(); x++)
    {
        if (x && s[x-1] == ' ' && s[x] == ' ')
            abort();
        if (x && s[x-1] == ':' && s[x] == ':')
            abort();
        if (!('a' <= s[x] && s[x] <= 'z') && !('A' <= s[x] && s[x] <= 'Z') && !('0' <= s[x] && s[x] <= '9') && s[x] != ':' && s[x] != ' ')
            abort();
        if (s[x] == ':')
        {
            if (ru)
            {
                cout<<cur<<"\n";
                cur = "";
                ru = false;
            }
            else
                ru = true;
        }
        else if (ru)
            cur += s[x];
    }
}
