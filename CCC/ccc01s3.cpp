#include <bits/stdc++.h>

using namespace std;

vector<vector<bool>> adj(27, vector<bool>(27));
vector<bool> vis(27);

bool BFS()
{
    fill(vis.begin(), vis.end(), false);
    queue<int> buf;
    buf.push(0);
    while (!buf.empty())
    {
        int u = buf.front();
        if (u == 1) return false;
        buf.pop();
        for (int x = 0; x < 27; x++)
            if (adj[u][x] && !vis[x])
                buf.push(x), vis[x] = true;
    }
    return true;
}

int main() 
{
    char a, b;
    vector<pair<char,char>> ed;
    scanf(" %c %c", &a, &b);
    while (a != '*' && b != '*')
    {
        ed.push_back({a, b});
        adj[a-'A'][b-'A'] = adj[b-'A'][a-'A'] = true;
        scanf(" %c %c", &a, &b);
    }
    int c = 0;
    for (auto &x : ed)
    {
        adj[x.first-'A'][x.second-'A'] = adj[x.second-'A'][x.first-'A'] = false;
        if (BFS())
            printf("%c%c\n", x.first, x.second), c++;
        adj[x.first-'A'][x.second-'A'] = adj[x.second-'A'][x.first-'A'] = true;
    }
    printf("There are %i disconnecting roads.", c);
    return 0;
}
