#include <bits/stdc++.h>

using namespace std;

bool includedChars[26];
bool contains [26][26];
vector<int> adj[52];
bool vis[52];
queue <int> buf;

int main()
{
    int n;
    char a, b, c[100];
    scanf("%i", &n);
    for (int x = 0; x < n; x++)
    {
        scanf(" %c %s %c", &a, &c, &b);
        adj[a -'A'].push_back(b -'A' < 26 ? b - 'A' : b - 71);
        includedChars[a-'A'] = true;
        if (b-'A' < 26)
            includedChars[b-'A'] = true;
    }
    for (int src = 0; src < 26; src++)
    {
        if (includedChars[src])
        {
            for (int x = 0; x < 52; x++)
                vis[x] = false;
            vis[src] = true;
            buf.push(src);
            while (!buf.empty())
            {
                int u = buf.front();
                buf.pop();
                for (int x = 0; x < adj[u].size(); x++)
                {
                    if (adj[u][x] > 25)
                        contains[src][adj[u][x]-26] = true;
                    else if (!vis[adj[u][x]])
                    {
                        vis[adj[u][x]] = true;
                        buf.push(adj[u][x]);
                    }
                }
            }
        }
    }
    for (int x = 0; x < 26; x++)
    {
        if (includedChars[x])
        {
            printf("%c = {", x + 'A');
            for (int y = 0; y < 26; y++)
            {
                if (contains[x][y])
                {
                    printf("%c", y + 'a');
                    for (int z = y+1; z < 26; z++)
                    {
                        if (contains[x][z])
                        {
                            printf(",");
                            break;
                        }
                    }
                }
            }
            printf("}\n");
        }
    }
    return 0;
}
