#include <bits/stdc++.h>

using namespace std;
 
struct door
{
    int nextRoom, nextDoor;
    bool valid;
};
 
struct node
{
    vector<door> doors;
    unordered_map<int, int> doorMap;
};

 
int main()
{
    int q, n, a, b;
    scanf("%i", &n);
    vector<node> adj (n);
    vector<int> pDist (n,0), sDist(n,-1);
    for (int x = 0; x < n; x++)
    {
        scanf("%i", &a);
        adj[x].doors.resize(a);
        for (int y = 0; y < a; y++)
        {
            scanf("%i", &b);
            b--;
            adj[x].doors[y].nextRoom = b, adj[x].doors[y].valid = true;
            adj[b].doorMap[x] = y;
        }
    }
    for (auto &x : adj)
        for (auto &y : x.doors)
            y.nextDoor = (x.doorMap[y.nextRoom] ? x.doorMap[y.nextRoom] : adj[y.nextRoom].doors.size()) - 1;

    for (int x = 0; x < n; x++)
        for (int y = 0; y < adj[x].doors.size(); y++)
            if (adj[x].doors[y].valid)
                for (int vis = 0, dist = 0, cRoom = x, cDoor = y; vis < 2; dist++)
                {
                    if (sDist[cRoom] != -1) pDist[cRoom] = max(pDist[cRoom], dist - sDist[cRoom]);
                    sDist[cRoom] = dist, adj[cRoom].doors[cDoor].valid = false;
                    int nRoom = adj[cRoom].doors[cDoor].nextRoom, nDoor = adj[cRoom].doors[cDoor].nextDoor;
                    cRoom = nRoom, cDoor = nDoor;
                    if (cRoom == x && cDoor == y) vis++;
                }

    scanf("%i", &q);
    while (q--)
    {
        scanf("%i", &a);
        printf("%i\n", pDist[a-1]);
    }
    return 0;
}
