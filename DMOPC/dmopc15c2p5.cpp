#include <bits/stdc++.h>

using namespace std;

struct line
{
    long long m, b, i;
    double lower_x = (double)INT_MIN;
    bool chk = false;
    friend bool operator<(const line aa, const line bb)
    {
        if (aa.chk || bb.chk)
            return aa.lower_x < bb.lower_x;
        return (aa.m < bb.m || (aa.m == bb.m && aa.b < bb.b));
    }
    inline double intersect(line &a)
    {
        return (a.b-this->b)/(double)(this->m-a.m);
    }
};

int main()
{
    int n, q;
    scanf("%i%i", &n, &q);
    vector<line> aa(n);
    for (int x = 0; x < n; x++)
    {
        scanf("%lli%lli", &aa[x].b, &aa[x].m);
        aa[x].i = x;
    }
    sort(aa.begin(), aa.end());
    vector<line> fin;
    for (auto &x : aa)
    {
        while (!fin.empty() && fin.back().m == x.m)
            fin.pop_back();
        while (fin.size() >= 2 && (x.intersect(fin[fin.size()-2]) <= fin.back().intersect(fin[fin.size()-2])))
        {
            if (x.intersect(fin[fin.size()-2]) == fin.back().intersect(fin[fin.size()-2]) && x.i >= fin.back().i)
                break;
            fin.pop_back();
        }
        fin.push_back(x);
    }
    for (int x = 1; x < fin.size(); x++)
        fin[x].lower_x = fin[x].intersect(fin[x-1]);
    while (q--)
    {
        scanf("%i", &n);
        auto it = lower_bound(fin.begin(), fin.end(), line{0, 0, 0, (double)n, true});
        if(!(it->lower_x == n && it->i < (it-1)->i))
            --it;
        printf("%lli\n", it->i);
    }
}
