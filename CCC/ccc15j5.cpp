#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> aa;

int next(int a, int b)
{
    if (a < b) return 0;
    else if (b == 1 || a == b) return 1;
    else if (aa[a][b] != INT_MAX) return aa[a][b];
    return aa[a][b] = next(a-1, b-1) + next(a-b, b);
}

int main()
{
    int n, k;
    scanf("%i%i", &n, &k);
    aa.resize(n+1);
    for (auto &x : aa)
        x.resize(n+1, INT_MAX);
    printf("%i", next(n, k));
}
