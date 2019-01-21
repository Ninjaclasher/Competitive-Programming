#include <bits/stdc++.h>

using namespace std;

struct qu
{
    int x, y, z, i;
    friend bool operator<(qu &a, qu &b)
    {
        return a.x < b.x;
    }
};

int main()
{
    int q;
    string s;
    cin>>s;
    vector<deque<int>> buf(2);
    for (int x = 0; x < s.size(); x++)
        buf[s[x]-'0'].push_back(x+1);
    scanf("%i", &q);
    vector<qu> que(q);
    for (int z = 0; z < q; z++)
    {
        auto &x = que[z];
        scanf("%i%i%i", &x.x, &x.y, &x.z);
        x.i = z;
    }
    sort(que.begin(), que.end());
    vector<int> ans(q);
    for (auto &x : que)
    {
        while (!buf[x.z].empty() && buf[x.z].front() < x.x)
            buf[x.z].pop_front();
        ans[x.i] = buf[x.z].size() < x.y ? -1 : buf[x.z][x.y-1];
    }
    for (auto &x : ans)
        printf("%i\n", x);
}
