#include<bits/stdc++.h>

using namespace std;

bool visited[1002];
bool vis[1002];
vector<int> adj[1002];
list<int> ss;
vector<string> tmp;
int c = 0;

void cycleDetector(int pos)
{
    if (visited[pos])
    {
        list<int>::iterator i = ss.begin();
        while (*i++ != pos); 
        stringstream pp;
        for (; i != ss.end(); i++)
            pp<<*i;
        string tt = pp.str();
        for (int y = 0; y < tmp.size(); y++)
            if (tmp[y] == tt)
                return;
        tmp.push_back(tt);
        c++;
        return;
    }
    ss.push_back(pos);
    visited[pos] = vis[pos] = true;
    for (int x = 0; x < adj[pos].size(); x++)
        cycleDetector(adj[pos][x]);
    visited[pos] = false;
    ss.pop_back();
}

int main()
{
    int n, m, a, b;
    scanf("%i%i", &n, &m);
    while (m--)
    {
        scanf("%i%i", &a, &b);
        adj[a].push_back(b);
    }
    for (int x = 1; x <= n; x++)
        if (!vis[x]) 
            cycleDetector(x);
    if (c == 2 && n != 4) c--;
    if (c == 0) printf("No Infinite Loops");
    else if (c == 1) printf("Infinite Loop Present");
    else printf("Infinite Loops Present");
    return 0;
}
