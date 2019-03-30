#include <bits/stdc++.h>

using namespace std;

struct node
{
    int ch[26];
    int len;
    int suff;
    int cnt;
    int endpos;
    int lazy;
};

struct PalindromeTree
{
    string s;
    vector<node> st;
    int suff, cc = 0;
    PalindromeTree(string t) : s(t)
    {
        st.resize(s.size()+3);
        cc = suff = 2;
        st[1].len = -1;
        st[2].len = 0;
        st[1].suff = st[2].suff = 1;
        for (int x = 0; x < s.size(); x++)
            insert(x);
    }

    bool insert(int pos)
    {
        int cur = suff;
        int chr = s[pos] - 'a';
        
        while (true)
        {
            int pp = pos-st[cur].len-1;
            if (pp >= 0 && s[pp] == s[pos])
                break;
            cur = st[cur].suff;
        }

        suff = st[cur].ch[chr];
        if (suff)
        {
            st[suff].lazy++;
            return false;
        }
        
        st[cur].ch[chr] = suff = ++cc;
         
        st[cc].len = st[cur].len + 2;
        st[cc].endpos = pos;
        st[cc].lazy = 1;

        if (st[cc].len == 1)
        {
            st[cc].suff = 2;
            st[cc].cnt = 1;
        }
        else
        {
            while (true)
            {
                cur = st[cur].suff;
                int pp = pos-st[cur].len-1;
                if (pp >= 0 && s[pp] == s[pos])
                    break;
            }
            st[cc].suff = st[cur].ch[chr];
            st[cc].cnt = st[st[cc].suff].cnt + 1;
        }
        return true;
    }
};

int main()
{
    string s;
    cin >> s;
    PalindromeTree pt(s);
    long long ans = 0;
    for (int x = pt.cc; x >= 2; x--)
    {
        if (pt.st[x].lazy)
            pt.st[pt.st[x].suff].lazy += pt.st[x].lazy;
        ans = max(ans, (long long)pt.st[x].lazy * pt.st[x].len);
    }
    printf("%lli\n", ans);
}
