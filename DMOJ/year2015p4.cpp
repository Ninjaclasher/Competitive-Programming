#include <bits/stdc++.h>

using namespace std;

const int MAXV = 1005;

struct op
{
    int t;
    char a, b;
    int px, py;
};

vector<vector<int>> dist(MAXV, vector<int>(MAXV, INT_MAX));
op par[MAXV][MAXV];

queue<pair<int,int>> buf;

void push(int va1, int vb1, int va2, int vb2, int t, char a, char b = '\0')
{
    if (dist[va2][vb2] > dist[va1][vb1] + 1)
    {
        dist[va2][vb2] = dist[va1][vb1] + 1;
        buf.push({va2, vb2});
        par[va2][vb2] = {t, a, b, va1, vb1};
    }
}

int main()
{
    int va, vb, m;
    scanf("%i%i%i", &va, &vb, &m);
    dist[0][0] = 0;
    buf.push({0, 0});
    while (!buf.empty())
    {
        int v1 = buf.front().first, v2 = buf.front().second;
        if (v1 == m || v2 == m)
        {
            vector<string> ops;
            while (v1 != 0 || v2 != 0)
            {
                string ret;
                if (par[v1][v2].t == 0)
                    ret = "fill ";
                else if (par[v1][v2].t == 1)
                    ret = "chug ";
                else
                    ret = "pour ";
                ret += par[v1][v2].a;
                if (par[v1][v2].b)
                {
                    ret += " ";
                    ret += par[v1][v2].b;
                }
                ops.push_back(ret);
                int n1 = par[ v1][v2].px;
                int n2 = par[v1][v2].py;
                v1 = n1;
                v2 = n2;
            }
            reverse(ops.begin(), ops.end());
            for (auto &x : ops)
                cout<<x<<"\n";
            return 0;
        }
        buf.pop();
        push(v1, v2, va, v2, 0, 'A');
        push(v1, v2, v1, vb, 0, 'B');
        push(v1, v2, 0, v2, 1, 'A');
        push(v1, v2, v1, 0, 1, 'B');
        int c = min(v1, vb-v2);
        push(v1, v2, v1-c, v2+c, 2, 'A', 'B');
        c = min(v2, va-v1);
        push(v1, v2, v1+c, v2-c, 2, 'B', 'A');
    }
    cout<<"Not possible\n";
}
