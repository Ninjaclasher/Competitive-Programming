#include <bits/stdc++.h>

using namespace std;

struct ele
{
    int i = 0;
    string a;
    friend bool operator<(ele &i, ele &j)
    {
        return i.a.size() < j.a.size();
    }
};

vector<int> pos(100005);
vector<ele> arr;

bool gett(int i, char c)
{
    for (pos[i] = arr[i].i; pos[i] < arr[i].a.size(); pos[i]++)
        if (arr[i].a[pos[i]] == c)
            return true;
    return false;
}

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n;
    cin>>n;
    arr.resize(n);
    for (auto &x : arr)
        cin>>x.a, x.i = 0;
    sort(arr.begin(), arr.end());
    string ret = "";

    for (char c = 'z'; c >= 'a';)
    {
        for (int x = 0; x < n; x++)
            if (!gett(x, c))
                goto nxt;
        ret += c;
        for (int x = 0; x < n; x++)
            arr[x].i = pos[x]+1;
        c++;
nxt:;
    c--;
    }


    if (ret.empty())
        printf("-1\n");
    else
        cout<<ret<<"\n";
}
