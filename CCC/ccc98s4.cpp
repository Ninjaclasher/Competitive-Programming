#include <bits/stdc++.h>

using namespace std;

list<string> split(string a, char c)
{
    string t = "";
    list<string> ret;
    for (auto &x : a)
    {
        if (x == c)
        {
            if (!t.empty())
                ret.push_back(t);
            t = "";
        }
        else
            t += x;
    }
    if (!t.empty())
        ret.push_back(t);
    return ret;
}


int main()
{
    int n;
    scanf("%i", &n);
    while(n--)
    {
        string a;
        do getline(cin, a); while(a.empty());
        list<string> aa = split(a, ' ');
        for (auto x = aa.begin(); x != aa.end();)
        {
            if (*x == "X" && aa.size() > 3)
            {
                auto bef = x; --bef;
                auto aft = x; ++aft;
                aa.insert(x, "(" + *bef + " " + *x + " " + *aft + ")");
                aa.erase(bef);
                aa.erase(aft);
                auto xx = x;
                ++x;
                aa.erase(xx);
            }
            else
                ++x;
        }
        for (auto x = aa.begin(); x != aa.end();)
        {
            if ((*x == "+" || *x == "-") && aa.size() > 3)
            {
                auto bef = x; --bef;
                auto aft = x; ++aft;
                aa.insert(x, "(" + *bef + " " + *x + " " + *aft + ")");
                aa.erase(bef);
                aa.erase(aft);
                auto xx = x;
                ++x;
                aa.erase(xx);
            }
            else
                ++x;
        }
        for (auto &x : aa)
            cout<<x<<" ";
        cout<<"\n\n";
    }
}
