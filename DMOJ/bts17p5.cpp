#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> freq(26);

struct rr
{
    char t;
    int n, be;
    friend bool operator<(rr &a, rr &b)
    {
        return a.be < b.be;
    } 
};

int main()
{
    int n, m;
    scanf("%i%i", &n, &m);
    string a(n, '\0');
    vector<rr> oo(m);
    for (auto &x : oo)
        scanf(" %c%i%i", &x.t, &x.n, &x.be), --x.be;
    sort(oo.begin(), oo.end());
    for (auto &x : oo)
    {
        int c = x.t - 'a';
        if (freq[c].first > x.n)
            return 0 * printf("-1");
        else if (freq[c].first == x.n)
            freq[c].second = x.be + 1;
        else
        {
            for (int y = freq[c].second; freq[c].first < x.n && y <= x.be; y++)
                if (a[y] == '\0')
                    freq[c].first++, a[y] = x.t;
            if (freq[c].first < x.n)
                return 0 * printf("-1");
            freq[c].second = x.be + 1;
        }
    }
    for (int x = 0; x < a.length(); x++)
    {
        if (a[x] == '\0')
            for (int y = 0; y < 26 && a[x] == '\0'; y++)
                if (freq[y].second <= x)
                    a[x] = y+'a';
        if (a[x] == '\0')
            return 0 * printf("-1");
    }
    cout<<a;
}
