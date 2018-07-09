#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> sparseTable(300002, vector<int> (19));
vector<int> height(300002), top(300002);

int lca(int a, int b)
{
    if (height[a] < height[b]) 
        swap(a, b);
    int diff = height[a] - height[b];
    for (int x = 0; x < sparseTable[0].size(); x++)
        if ((diff >> x) & 1) 
            a = sparseTable[a][x];
    if (a == b) return a;
    for (int x = sparseTable[0].size()-1; x >= 0; x--)
        if (sparseTable[a][x] != sparseTable[b][x])
            a = sparseTable[a][x], b = sparseTable[b][x];
    return sparseTable[a][0];
}

int main()
{
    int n, a, b; 
    char t;
    scanf("%i", &n);
    for(int x = 1; x <= n; x++)
    {
        scanf(" %c%i", &t, &a);
        switch (t)
        {
            case 'a':;
                top[x] = x, height[x] = height[top[a]]+1, sparseTable[x][0] = top[a];
                for (int y = 1; y < sparseTable[0].size(); y++)
                    sparseTable[x][y] = sparseTable[sparseTable[x][y-1]][y-1];
            break;
            case 'b':;
                top[x] = sparseTable[top[a]][0];
                printf("%i\n", top[a]);
            break;
            case 'c':;
                scanf("%i", &b);
                top[x] = top[a];
                printf("%i\n", height[lca(top[a], top[b])]);
            break;
        }
    }
    return 0;
}
