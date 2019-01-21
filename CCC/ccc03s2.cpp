#include <bits/stdc++.h>

using namespace std;



bool vowel(char c)
{
    switch (c)
    {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            return true;
    }
    return false;
}

string strip(string a)
{
    string ret = "";
    while (!a.empty() && !vowel(a.back()) && a.back() != ' ')
        ret += a.back(), a.pop_back();
    if (!a.empty() && a.back() != ' ')
        ret += a.back();
    reverse(ret.begin(), ret.end());
    return ret;
}

bool rhyme(string &a, string &b)
{
    for (auto &x : a)
        x = tolower(x);
    for (auto &x : b)
        x = tolower(x);
    return strip(a) == strip(b);
}

int main()
{
    int n;
    scanf("%i", &n);
    while (n--)
    {
        string a, b, c, d;
        do getline(cin, a); while (a.empty());
        do getline(cin, b); while (b.empty());
        do getline(cin, c); while (c.empty());
        do getline(cin, d); while (d.empty());
        bool ab = rhyme(a, b);
        bool bc = rhyme(b, c);
        bool cd = rhyme(c, d);
        bool da = rhyme(a, d);
        bool ac = rhyme(a, c);
        bool bd = rhyme(b, d);
        if (ab && bc && cd)
            printf("perfect\n");
        else if (ab && cd)
            printf("even\n");
        else if (ac && bd)
            printf("cross\n");
        else if (da && bc)
            printf("shell\n");
        else
            printf("free\n");
    }
}
