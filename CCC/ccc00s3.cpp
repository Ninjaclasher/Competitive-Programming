#include <bits/stdc++.h>

using namespace std;
int n;

const int MAXN = 105;
vector<vector<int>> adj(MAXN);
vector<vector<bool>> vis(MAXN, vector<bool>(MAXN));

void bfs(int src)
{
    queue<int> buf;
    buf.push(src);
    vis[src][src] = true;
    while (!buf.empty())
    {
        int u = buf.front();
        buf.pop();
        for (auto &x : adj[u])
            if (!vis[src][x])
                vis[src][x] = true, buf.push(x);
    }
}

string gline()
{
    string a;
    do getline(cin, a); while (a.empty());
    return a;
}

int main()
{
    scanf("%i", &n);
    string a, b, c;
    vector<string> content(MAXN);
    vector<string> url(MAXN);
    map<string,int> mp;
    vector<vector<string>> tmpadj(MAXN);
    int urlc = 1;
    for (int x = 1; x <= n; x++)
    {
        cin>>a;
        if (!mp[a])
            mp[a] = urlc++;
        for (cin>>b; b != "</HTML>"; cin>>b)
            content[x] += " " + b;
        for (int y = 0; y < content[x].size(); y++)
        {
            if (content[x].substr(y, 6) == "HREF=\"")
            {
                string t = "";
                for (int z = y+6; content[x][z]!= '\"'; z++)
                    t += content[x][z];
                cout<<"Link from "<<a<<" to "<<t<<"\n";
                if (!mp[t])
                    mp[t] = urlc++;
                adj[mp[a]].push_back(mp[t]);
            }
        }
    }
    for (int x = 1; x <= urlc; x++)
        bfs(x);
    a = gline();
    while (a != "The End")
    {
        b = gline();
        if (b == "The End")
            break;
        if (vis[mp[a]][mp[b]])
            cout<<"Can surf from "<<a<<" to "<<b<<".\n";
        else
            cout<<"Can't surf from "<<a<<" to "<<b<<".\n";
        a = gline();
    }
}
