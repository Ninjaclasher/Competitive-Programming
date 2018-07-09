#include <bits/stdc++.h>

using namespace std;

vector<int> bit(10003);
vector<pair<string,int>> name(10003);
map<string,int> pos;

int query(int idx)
{
    int sum = 0;
    for (; idx > 0; idx -= idx&-idx)
        sum += bit[idx];
    return sum;
}

void update(int idx, int val)
{
    for (; idx < bit.size(); idx += idx&-idx)
        bit[idx] += val;
}

int toMass(string name)
{
    int sum = 0;
    for (auto x : name)
        sum += x-'`';
    return sum;
}

int main()
{
    cin.sync_with_stdio(0);
    cout.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c, n = 0;
    string a, b;
    char t;
    cin>>c;
    while (c--)
    {
        cin>>t;
        if (t != 'N')
        {
            cin>>a;
            if (t != 'A')
                cin>>b;
        }
        switch (t)
        {
            case 'A':
            {
                if (pos[a] != 0)
                    cout<<"Can't add "<<a<<"\n";
                else
                {
                    pos[a] = ++n, name[n] = make_pair(a, toMass(a));
                    update(n, name[n].second);
                }
            }
            break;
            case 'S':
            {
                int posA = pos[a], posB = pos[b];
                update(posA, name[posB].second - name[posA].second);
                update(posB, name[posA].second - name[posB].second);
                pair<string,int> tmpN = name[posA];
                name[posA] = name[posB], name[posB] = tmpN;
                pos[a] = posB, pos[b] = posA;
            }
            break;
            case 'M':
            {
                int posA = pos[a], posB = pos[b];
                if (posA > posB)
                    swap(posA, posB);
                cout<<query(posB) - query(posA-1)<<"\n";
            }
            break;
            case 'R':
            {
                pair<string,int> tmpN = make_pair(b, toMass(b));
                int posA = pos[a];
                update(posA, tmpN.second - name[posA].second);
                pos.erase(a);
                pos[b] = posA, name[posA] = tmpN;
            }
            break;
            case 'N':
                cout<<n<<"\n";
            break;
        }
    }
    return 0;
}
