#include <bits/stdc++.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

vector<vector<int>> adj (100001);
int s, t, n = 0, m, a, b;

void uAddEdge (int node1, int node2)
{
    adj[node1].push_back(node2);
    adj[node2].push_back(node1);
}

bool q1util(int src, vector<int>::iterator begin, vector<int>::iterator end)
{
    stack<int> buf;
    vector<bool> vis (100001, false);
    auto startPos = find(begin,end,src);
    buf.push(src);
    while (!buf.empty())
    {
        int v = buf.top();
        auto vPos = find(begin, end, v);
        buf.pop();
        for (auto &x : adj[v])
        {
            bool BE = (startPos == begin || vPos == begin || startPos == end-1 || vPos == end-1);
            auto it = find(begin, end, x);
            if (!vis[x] && (it == end || (abs(it - startPos) > 1 && (BE ? abs((it-end)%(end-begin)) > 1 : true) && abs(it - vPos) > 1)))
            {
                vis[x] = true;
                buf.push(x);
            }
            if (it != end && *it != src && abs(it - startPos) > 1 && (BE ? abs((it-end)%(end-begin)) > 1 : true) && abs(it - vPos) > 1)
                return true;
        }
    }
    return false;
}

bool q1()
{
    stack<vector<int>> buf;
    buf.push (vector<int> {1}); 
    while (!buf.empty())
    {
        vector<int> tmp = buf.top();
        buf.pop();
        int v = tmp.back();
        for (auto &x : adj[v])
        {
            bool found = false;
            vector<int>::iterator point;
            for (auto y = tmp.begin(); y != tmp.end(); y++)
            {
                if (!found && x == *y) found = true, point = y;
                if (found && tmp.end() - point > 3 && q1util(*y, point, tmp.end())) return true;
            }
            tmp.push_back(x);
            if (!found) buf.push(tmp);
            tmp.pop_back();
        }
    }
    return false; 
}
/*
bool q3()
{
    vector<int> idx(1000001);
    vector<int> cyc(1000001, -1);
    vector<int> buf = {1};
    while (!buf.empty())
    {
        int v = buf.back();
        int x = adj[v][idx[v]++];
        if (idx[x] != adj[x].size() && x != buf[buf.size()-1])
        {
            buf.push_back(x);
            if (idx[x])
            {
                buf.pop_back();
                for (int y = buf.size()-1; y >= 0; y--)
                {
                    cyc[buf[y]] = 0;
                    if (buf.size()-y > 3) return true;
                    else if (buf[y] == x) break;
                }
            }
        }
        while (!buf.empty() && idx[buf.back()] == adj[buf.back()].size())
        {
            idx[buf.back()] &= cyc[buf.back()]; 
            buf.pop_back();
        }
    }
    return false;
}*/

int idx[1000001], cyc[1000001], buf[100000];

bool q3()
{
    memset(idx, 0, sizeof(idx));
    memset(cyc, -1, sizeof(cyc));

    idx[100000] = 2;
    buf[0] = 100000;
    buf[1] = 1;
    int ii = 1;
    while (ii)
    {
        int x = adj[buf[ii]][idx[buf[ii]]++];
        if (idx[x] != adj[x].size() && x != buf[ii-1])
        {
            buf[++ii] = x;
            if (idx[x])
            {
                int y = --ii;
                do
                    cyc[buf[y]] = 0;
                while (buf[--y] != x);
                if (ii-y >= 3) return true;
            }
        }
        while (idx[buf[ii]] == adj[buf[ii]].size())
        {
            idx[buf[ii]] &= cyc[buf[ii]];
            ii--;
        }
    }
    return false;
}

bool q5util(vector<vector<int>> &tmp)
{
    for (auto &i : tmp)
        for (auto &j : tmp)
            if (i.begin() != j.begin())
                for (auto &x : i)
                    for (auto &y : j)
                        if (x != y)
                            return true;
    return false;
}

bool q5()
{
    stack<vector<int>> buf;
    buf.push (vector<int> {1});
    while (!buf.empty())
    {
        vector<int> tmp = buf.top();
        buf.pop();
        int v = tmp.back();
        for (auto &x : adj[v])
        {
            bool found = false;
            vector<int>::iterator point;
            vector<vector<int>> possibilities;
            for (auto y = tmp.begin(); y != tmp.end(); y++)
            {
                if (x == *y) found = true, point = y;
                if (found && tmp.end() - point > 2)
                {
                    vector<int> tmp2;
                    for (auto &xx : adj[*y])
                        if (find(point, tmp.end(), xx) == tmp.end())
                            tmp2.push_back(xx);
                    possibilities.push_back(tmp2);
                }
            }
            if (tmp.end() - point > 2 && q5util(possibilities))
                    return true;
            tmp.push_back(x);
            if (!found) buf.push(tmp);
            tmp.pop_back();
        }
    }
    return false;
}

int main()
{
    scan(s); scan(t);
    while (t--)
    {
        scan(n); scan(m);
        for (int y = 0; y < m; y++)
        {
            scan(a); scan(b);
            uAddEdge(a, b);
        }
        switch(s)
        {
            case 1:
                printf("%s", q1() ? "YES\n" : "NO\n");
            break;
            case 2:
                printf("%s", m == n-1 ? "NO\n" : "YES\n");
            break;
            case 3:
                printf("%s", q3() ? "YES\n" : "NO\n");
            break;
            case 4:
                printf("%s", find_if(adj.begin(), adj.begin()+n+1, [](auto &x) {return x.size()>=3;}) != adj.begin()+n+1 ? "YES\n" : "NO\n");
            break;
            case 5:
                printf("%s", q5() ? "YES\n" : "NO\n");
            break;
        }
        fill(adj.begin(), adj.begin()+n+1, vector<int>());
    }
    return 0;
}
