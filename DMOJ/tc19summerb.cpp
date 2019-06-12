#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i", &n);
    vector<double> cnt;
    for (int i = 0; i < n; i++)
    {
        int k;
        scanf("%i", &k);
        vector<double> cur(k);
        for (auto &x : cur)
            scanf("%lf", &x);
        sort(cur.rbegin(), cur.rend());
        cnt.push_back(cur[0]);
        double c = cur[0];
        for (int x = 1; x < k; x++)
        {
            double d = (1 - c) * cur[x];
            cnt.push_back(d);
            c += d;
        }
    }
    sort(cnt.rbegin(), cnt.rend());
    double s = 0;
    for (int x = 0; x < cnt.size(); x++)
    {
        s += cnt[x];
        printf("%.20lf\n", s);
    }
}
