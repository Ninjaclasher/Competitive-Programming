#include <bits/stdc++.h>

using namespace std;

vector<int> nn;
vector<bool> eat(1001);
vector<bool> calVis(10000001);
int ma = 0, c, n;


bool next(int cal)
{
    if (cal >= c) return false;
    if (cal > ma) ma = cal;
    if (ma == c-1) return true;
    calVis[cal] = true;
    for (int x = 0; x < n; x++)
    {
        if (!eat[x])
        {
            eat[x]=true;
            if (!calVis[cal+nn[x]] && next(cal+nn[x])) return true;
            eat[x]=false;
        }
    }
    return false;
}

int main()
{
    scanf("%i%i", &c, &n);
    nn.resize(n);
    for (int x = 0; x < n; x++)
        scanf("%i", &nn[x]);
    //sort(nn.rbegin(), nn.rend());
    next(0);
    printf("%i\n", ma);
    return 0;
}
