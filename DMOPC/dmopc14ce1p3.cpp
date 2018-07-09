#include <bits/stdc++.h>

using namespace std;

int totalEnergy = 0;
bool atom[1001];
int connections[1001][1001];

class Graph
{
    int V;
    typedef pair<int,int> iPair;
    vector<int> *adj;

public:
    Graph(int);
    pair<int,int> countBond();
    void uAddEdge(int, int);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new vector<int> [V];
}

void Graph::uAddEdge (int node1, int node2)
{
    adj[node1].push_back(node2);
    adj[node2].push_back(node1);
}

pair<int,int> Graph::countBond()
{
    iPair bonds;
    for (int x = 1; x < V; x++)
    {
        if (adj[x].size() == 4)
            atom[x] = true, bonds.first++;
        else if (adj[x].size() == 1)
            atom[x] = false, bonds.second++;
        else
        {
            bonds.first = -1;
            return bonds;
        }
    }
    for (int x = 1; x < V; x++)
    {
        for (int y = 1; y < V; y++)
        {
            if (connections[x][y])
            {
                if (atom[x] && atom[y])
                {
                    switch(connections[x][y])
                    {
                    case 1:
                        totalEnergy +=346;
                    break;
                    case 2:
                        totalEnergy += 615;
                    break;
                    }
                }
                else
                    totalEnergy+=413;
            }
        }
    }
    return bonds;
}

int main()
{
    int n, m, a, b;
    scanf("%i%i", &n, &m);
    Graph g (n+1);
    for (int x = 0; x < m; x++)
    {
        scanf("%i%i", &a, &b);
        g.uAddEdge(a, b);
        connections[min(a,b)][max(a,b)]++;
    }
    pair<int,int> kl = g.countBond();
    if (kl.first == -1)
    {
        printf("Impossible\n");
        return 0;
    }
    printf("%i\nC", totalEnergy);
    if (kl.first != 1)
        printf("%i", kl.first);
    printf("H");
    if(kl.second != 1)
        printf("%i", kl.second);
    return 0;
}
