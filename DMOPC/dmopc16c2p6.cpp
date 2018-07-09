#include <bits/stdc++.h>

using namespace std;

struct folder
{
    folder* par;
    string name;
    map<string, int> mp;
    vector<folder*> fo;
};

vector<string> ls;

vector<string> split(string &in, char c)
{
    vector<string> ret;
    string tmp;
    for (auto &x : in)
    {
        if (x == c)
            ret.push_back(tmp), tmp = "";
        else
            tmp += x;
    }
    if (!tmp.empty())
        ret.push_back(tmp);
    return ret;
}

void dfs(folder* u)
{
    ls.push_back(u->name);
    for (auto x : u->fo)
        dfs(x);
}

int main()
{
    int n, prev = -1, a;
    cin.tie(0); cout.tie(0), ios_base::sync_with_stdio(0);
    cin>>n;
    string na, cmd;
    folder* root = new folder{NULL, "~", map<string, int>(), vector<folder*>()};
    folder* cur = root;
    while (n--)
    {
        cin>>a>>na;
        for(; prev >= a; prev--)
            cur = cur->par;
        cur->mp[na] = cur->fo.size();
        cur->fo.push_back(new folder{cur, na, map<string, int>(), vector<folder*>()});
        cur = cur->fo.back();
        prev = a;
    }
    cur = root;
    while (true)
    {
        do getline(cin, cmd); while (cmd.empty());
        vector<string> token = split(cmd, ' ');
        switch(token[0][0])
        {
            case 'l':
            {
                int i = 1;
                ls.clear();
                if (i < token.size() && token[i] == "-r")
                {
                    for (auto &x : cur->fo)
                        dfs(x);
                    i++;
                }
                else
                    for (auto &x : cur->fo)
                        ls.push_back(x->name);
                sort(ls.begin(), ls.end());
                bool printed = false;
                if (i < token.size() && token[i] == "|" && token[++i] == "grep")
                {
                    i++;
                    if (token[i][0] != '^')
                        token[i] = ".*" + token[i];
                    if (token[i].back() != '$')
                        token[i] += ".*";
                    regex chk (token[i]);
                    for (auto x : ls)
                        if (regex_match(x, chk))
                            cout<<x<<"\n", printed = true;
                }
                else
                    for (auto x : ls)
                        cout<<x<<"\n", printed = true;
                if (!printed)
                    cout<<"\n";
                cout<<"\n";
            }
            break;
            case 'c':
            {
                vector<string> path = split(token[1], '/');
                if (token[1][0] == '~' && token[1][1] == '/')
                {
                    cur = root;
                    for (int x = 1; x < path.size(); x++)
                        cur = cur->fo[cur->mp[path[x]]];
                }
                else
                    for (auto x : path)
                        cur = cur->fo[cur->mp[x]];
            }
            break;
            case 'm':
            case 't':
                cur->mp[token[1]] = cur->fo.size();
                cur->fo.push_back(new folder{cur, token[1], map<string, int>(), vector<folder*>()});
            break;
            case 'p':
            {
                string ret = "";
                for (auto x = cur; x != NULL; x = x->par)
                    ret = x->name + "/" + ret;
                cout<<ret<<"\n\n";
            }
            break;
            case 'e':
                cout<<"\n";
                return 0;
        }
    }
}
