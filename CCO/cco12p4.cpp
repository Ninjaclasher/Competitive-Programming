#include <bits/stdc++.h>

using namespace std;

vector<int> numChars;

pair<int,int> nextPos(pair<int,int> cur, char d)
{
    if (d == 'U')
    {
        if (!cur.first)
            return cur;
        cur.first--;
        cur.second = min(cur.second, numChars[cur.first]);
        return cur;
    }
    else if (d == 'D')
    {
        if (cur.first == numChars.size()-1)
            return cur;
        cur.first++;
        cur.second = min(cur.second, numChars[cur.first]);
        return cur;
    }
    else if (d == 'L')
    {
        if (cur.second == 0)
        {
            if (!cur.first)
                return cur;
            cur.first--;
            cur.second = numChars[cur.first];
            return cur;
        }
        else
        {
            cur.second--;
            return cur;
        }
    }
    else if (d == 'R')
    {
        if (cur.second == numChars[cur.first])
        {
            if (cur.first == numChars.size()-1)
                return cur;
            cur.first++;
            cur.second = 0;
            return cur;
        }
        else
        {
            cur.second++;
            return cur;
        }
    }
    else
        abort();
}

int main()
{
    int n;
    scanf("%i", &n);
    numChars.resize(n);
    for (auto &x : numChars)
        scanf("%i", &x), --x;
    vector<vector<int>> dist(100001, vector<int> (81, INT_MAX));
    int a, b;
    scanf("%i%i", &a, &b);
    --a, --b;
    dist[a][b] = 0;
    queue<pair<int,int>> buf;
    buf.push({a, b});
    while (!buf.empty())
    {
        pair<int,int> u = buf.front();
        buf.pop();
        for (auto &x : {'U', 'D', 'L', 'R'})
        {
            pair<int,int> ne = nextPos(u, x);
            if (u == ne)
                continue;
            if (dist[u.first][u.second]+1 < dist[ne.first][ne.second])
                dist[ne.first][ne.second] = dist[u.first][u.second]+1, buf.push(ne);
        }
    }
    scanf("%i%i", &a, &b);
    --a, --b;
    printf("%i\n", dist[a][b]);
}

