#include <bits/stdc++.h>

using namespace std;

#define getchar() (*_pinp?*_pinp++:(_inp[fread(_pinp=_inp, 1, 4096, stdin)]='\0', *_pinp++))
char _inp[4097], *_pinp=_inp;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int main()
{
    int n, k;
    deque<pair<long long, int>> buf;
    scan(n);
    if (n > (1 <<23)) abort ();
    scan(k);
    vector<long long> a (n+5);
    vector<int> jmp(n+5), path(n+5);
    buf.push_back(make_pair(0, 0));
    for (int x = 1; x <= n; x++)
        scan(a[x]);
    for (int x = 1; x <= n+1; x++)
    {
        while (!buf.empty() && x - buf.front().second > k) 
            buf.pop_front();
        path[x] = buf.front().second, a[x] += buf.front().first;
        while (!buf.empty() && buf.back().first >= a[x]) 
            buf.pop_back();
        buf.push_back({a[x], x});
    }
    printf("%lli\n", a[n+1]);
    int c = 0;
    for(int x = n+1; path[x]; x = path[x])
        jmp[c++] = path[x];
    while (c)
        printf("%i ", jmp[--c]);
}
