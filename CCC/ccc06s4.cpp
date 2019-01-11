#include <bits/stdc++.h>

using namespace std;

bool fail()
{
    printf("no\n");
    return false;
}

bool run(int n)
{
    vector<vector<int>> arr(n+1, vector<int>(n+1));
    for (int x = 1; x <= n; x++)
    {
        for (int y = 1; y <= n; y++)
        {
            scanf("%i", &arr[x][y]);
            if (arr[x][y] < 1 || arr[x][y] > n)
                return fail();                
        }
    }
    int id = -1;
    for (int x = 1; x <= n && !~id; x++)
    {
        bool t = true;
        for (int y = 1; y <= n; y++)
            t &= arr[x][y] == y;
        if (t)
            id = x;
    }
    if (!~id)
        return fail();
    bool f = true;
    for (int x = 1; x <= n; x++)
    {
        bool t = false;
        for (int y = 1; y <= n; y++)
            t |= (arr[x][y] == arr[y][x] && arr[x][y] == id);
        f &= t;
    }
    if (!f)
        return fail();
    for (int x = 1; x <= n; x++)
        for (int y = 1; y <= n; y++)
            for (int z = 1; z <= n; z++)
                if (arr[x][arr[y][z]] != arr[arr[x][y]][z])
                    return fail();
    printf("yes\n");
    return true;
}

int main()
{
    int n;
    for (scanf("%i", &n); n; scanf("%i", &n))
        run(n);
}
