#include<bits/stdc++.h>
#include <list>
#include <vector>
#include <cmath>

using namespace std;

struct location
{
    int x, y, r;
    location(int xx, int yy, int rr)
    {
        x = xx;
        y = yy;
        r = rr;
    }
};

double dis (int x1, int y1, int x2, int y2)
{
    return sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
}

class Graph
{
    int V;
    list<short> *adj;
public:
    Graph(int V);
    void addEdge(int, int);
    bool BFS(int, int);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<short>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

bool Graph::BFS(int s, int k)
{
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;
    list<short> queue;
    visited[s] = true;
    queue.push_back(s);
    list<short>::iterator i;

    while(!queue.empty())
    {
        s = queue.front();
        if (s == k)
            return true;
        queue.pop_front();
        for(i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if(!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
    return false;
}

int main()
{
    int b, q, x, y, r, c, d;
    scanf("%i%i", &b, &q);
    vector<location> w;
    Graph path(b);
    for (int i = 0; i < b; i++)
    {
        scanf("%i%i%i", &x, &y, &r);
        w.push_back(location(x, y, r));
    }
    for (int i = 0; i < b; i++)
    {
        for (int j = 0; j < b; j++)
        {
            if (i != j && dis(w[i].x, w[i].y, w[j].x, w[j].y) <= w[i].r)
                path.addEdge(i, j);
        }
    }
    for (int i = 0; i < q; i++)
    {
        scanf("%i%i", &c, &d);
        c--; d--;
        if (path.BFS(c, d))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
