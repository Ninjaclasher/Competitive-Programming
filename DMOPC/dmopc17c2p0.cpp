#include <bits/stdc++.h>

using namespace std;

inline int dist(int x, int y, int xx, int yy) {return (x-xx)*(x-xx) + (y-yy)*(y-yy);}

int main()
{
    vector<pair<int,int>> a (3);
    for (auto &x : a)
        scanf("%i%i", &x.first, &x.second);
    int d;
    scanf("%i", &d);
    d*=d;
    if (dist(a[2].first, a[2].second, a[0].first, a[0].second) <= d || dist(a[2].first, a[2].second, a[1].first, a[1].second) <= d)
        printf("Yes");
    else
        printf("No");
}
