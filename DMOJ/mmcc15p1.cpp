#include <bits/stdc++.h>

using namespace std;

vector<int> rnk, parent, rk;
stack<pair<int,int>> rr;

int find(int node)
{
    while (node != parent[node])
        node = parent[node];
    return node;
}

void Init(int N)
{
    rnk.resize(N+2, 1);
    parent.resize(N+2);
    rk.resize(N+2);
    int n = 0; 
    generate(parent.begin(), parent.end(), [&n] () {return n++;}); 
}

void AddEdge(int node1, int node2)
{
    int p1 = find(node1), p2 = find(node2);
    if (p1 == p2)
        rr.push(make_pair(-1, -1));
    else
    {
        if(rk[p2] < rk[p1])
            swap(p1, p2);
        rr.push(make_pair(p1,rk[p2]));
        parent[p1] = p2;
        rnk[p2] += rnk[p1];
        rk[p2] = rk[p1] + 1 > rk[p2] ? rk[p1] + 1 : rk[p2];
    }
}

void RemoveLastEdge()
{
    int p1 = rr.top().first, p2r = rr.top().second;
    if (p1 != -1)
    {
        int p2 = parent[p1];
        parent[p1] = p1;
        rnk[p2] -= rnk[p1];
        rk[p2] = p2r;
    }
    rr.pop();
}

int GetSize(int U)
{
    return rnk[find(U)];
}
