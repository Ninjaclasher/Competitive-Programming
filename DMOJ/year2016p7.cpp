#include <bits/stdc++.h>

using namespace std;

vector<int> ll, rr, light;
vector<vector<int>> st, pos;

int getMax(int a, int b)
{
    int k = b-a+1;
    for (int x = 31; x >= 0; x--)
    {
        if ((k>>x)&1)
        {
            k = x;
            break;
        }
    }
    if (st[k][a] >= st[k][b-(1<<k)+1])
        return pos[k][a];
    else
        return pos[k][b-(1<<k)+1];
}

int main()
{
    deque<int> maxQ, minQ;
    int n, k, q, a, b, l = 0;
    scanf("%i%i", &n, &k);
    light.resize(n), ll.resize(n, 1), rr.resize(n, 1);
    st.resize((int)ceil(log2(n))+1 , vector<int> (2*n)), pos.resize((int)ceil(log2(n))+1 , vector<int> (2*n));
    for (int x = 0; x < n; x++)
    {
        scanf("%i", &light[x]);
        while (!maxQ.empty() && maxQ.back() < light[x]) maxQ.pop_back();
        maxQ.push_back(light[x]);
        while (!minQ.empty() && minQ.back() > light[x]) minQ.pop_back();
        minQ.push_back(light[x]);
        while (maxQ.front()-minQ.front() > k)
        {
            if (maxQ.front() == light[l])
                maxQ.pop_front();
            if (minQ.front() == light[l])
                minQ.pop_front();
            rr[l] = x-l++;
        }
        ll[x] = x-l+1;
    }
    for (; l < n; rr[l] = n-l++);
    st[0] = rr;
    iota(pos[0].begin(), pos[0].end(), 0);
    for (int x = 1; x < st.size(); x++)
    {
        k = 1<<(x-1);
        for (int y = 0; y < n; y++)
        {
            st[x][y] = st[x-1][y], pos[x][y] = pos[x-1][y];
            if (st[x-1][y+k] > st[x][y])
                st[x][y] = st[x-1][y+k], pos[x][y] = pos[x-1][y+k];
        }
    }
    scanf("%i", &q);
    while (q--)
    {
        scanf("%i%i", &a, &b);
        a--, b--;
        if (rr[a] > b-a)
            printf("%i %i\n", a+1, b+1);
        else
        {
            int maxPos = getMax(a, b-ll[b]);
            if (min(ll[b],b-a+1) > rr[maxPos])
                printf("%i %i\n", b-min(ll[b],b-a)+2, b+1);
            else
                printf("%i %i\n", maxPos+1, maxPos+rr[maxPos]);
        }
    }
}
