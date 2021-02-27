#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    assert(s.length() <= 500000);
    int lcnt = 0, mcnt = 0, scnt = 0;
    for (auto &x : s)
    {
        if (x == 'L')
            lcnt++;
        else if (x == 'M')
            mcnt++;
        else if (x == 'S')
            scnt++;
        else
            abort();
    }
    int m_in_l_cnt = 0, s_in_l_cnt = 0;
    for (int x = 0; x < lcnt; x++)
    {
        if (s[x] == 'M')
            m_in_l_cnt++;
        else if (s[x] == 'S')
            s_in_l_cnt++;
    }
    int s_in_m_cnt = 0;
    for (int x = lcnt; x < lcnt + mcnt; x++)
        if (s[x] == 'S')
            s_in_m_cnt++;
    int m_in_s_cnt = 0;
    for (int x = lcnt + mcnt; x < lcnt + mcnt + scnt; x++)
        if (s[x] == 'M')
            m_in_s_cnt++;
    printf("%i\n", m_in_l_cnt + s_in_l_cnt + max(s_in_m_cnt, m_in_s_cnt));
}
