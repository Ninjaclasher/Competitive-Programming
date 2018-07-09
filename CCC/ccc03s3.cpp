#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int r, c, m;
    vector<int> rm;
    vector<vector<char>> aa(30, vector<char>(30, 'I'));
    scanf("%i%i%i", &m, &r, &c);
    for (int x = 1; x <= r; x++)
        for (int y = 1; y <= c; y++)
            scanf(" %c", &aa[x][y]);
    for (int x = 1; x <= r; x++)
    {
        for (int y = 1; y <= c; y++)
        {
            if (aa[x][y] == '.')
            {
                aa[x][y] = 'I';
                int s = 0;
                queue<pair<int,int>> buf;
                buf.push(make_pair(x, y));
                while (!buf.empty())
                {
                    int xx = buf.front().first, yy = buf.front().second;
                    buf.pop();
                    s++;
                    for (int i = 0; i < 4; i++)
                    {
                        int ax = 0, ay = 0;
                        switch(i)
                        {
                            case 0: ax++; break;
                            case 1: ax--; break;
                            case 2: ay++; break;
                            case 3: ay--; break;
                        }
                        if (aa[xx+ax][yy+ay] == '.')
                            aa[xx+ax][yy+ay] = 'I', buf.push(make_pair(xx+ax, yy+ay));

                    }
                }
                rm.push_back(s);
            }
        }
    }
    sort(rm.rbegin(), rm.rend());
    int d = 0;
    for (int x = 0; x < rm.size() && m-rm[x] >= 0; x++)
    {
        m -= rm[x];
        d++;
    }
    printf("%i room%s, %i square metre(s) left over", d, d==1 ? "" : "s", m);
    return 0;
}
