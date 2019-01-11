#include <bits/stdc++.h>

using namespace std;

using mat = vector<vector<int>>;

mat mult(mat &a, mat &b)
{
    mat ret;
    ret.resize(a.size()*b.size(), vector<int>(a[0].size()*b[0].size()));
    for (int x = 0; x < a.size(); x++)
        for (int y = 0; y < a[x].size(); y++)
            for (int i = 0; i < b.size(); i++)
                for (int j = 0; j < b[i].size(); j++)
                    ret[x*b.size()+i][y*b[i].size()+j] = a[x][y]*b[i][j];
    return ret;
}

int main()
{
    int n;
    scanf("%i", &n);
    int r, c;
    scanf("%i%i", &r, &c);
    mat a(r, vector<int> (c));
    for (auto &x : a)
        for (auto &y : x)
            scanf("%i", &y);
    n--;
    while (n--)
    {
        scanf("%i%i", &r, &c);
        mat b(r, vector<int>(c));
        for (auto &x : b)
            for (auto &y : x)
                scanf("%i", &y);
        a = mult(a, b);
    }
    int mir = INT_MAX, mar = INT_MIN;
    int mic = INT_MAX, mac = INT_MIN;
    int mi = INT_MAX, ma = INT_MIN;
    for (auto &x : a)
    {
        int sum = 0;
        for (auto &y : x)
        {
            sum += y;
            mi = min(mi, y);
            ma = max(ma, y);
        }
        mir = min(mir, sum);
        mar = max(mar, sum);
    }
    for (int x = 0; x < a[0].size(); x++)
    {
        int sum = 0;
        for (int y = 0; y < a.size(); y++)
            sum += a[y][x];
        mic = min(mic, sum);
        mac = max(mac, sum);
    }
    printf("%i\n%i\n%i\n%i\n%i\n%i\n", ma, mi, mar, mir, mac, mic);
}

