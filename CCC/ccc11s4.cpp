#include <bits/stdc++.h>

int supplied = 0;
int units[8], patients [8];

void addSupplied (int u,int p)
{
 int t = std::min(units[u], patients[p]);
 units[u] -= t;
 patients[p] -= t;
 supplied += t;
}

int main()
{
    for (int x = 0; x < 8; x++)
        scanf("%i", &units[x]);
    for (int x = 0; x < 8; x++)
        scanf("%i", &patients[x]);
    for (int x = 0; x < 8; x++)
    {
        switch (x)
        {
        case 1:
            addSupplied(1, x);
        break;
        case 2:
            addSupplied(2, x);
        break;
        case 3:
            addSupplied(3, x);
            addSupplied(2, x);
            addSupplied(1, x);
        break;
        case 4:
            addSupplied(4, x);
            addSupplied(2, x);
        break;
        case 5:
            addSupplied(5, x);
            addSupplied(4, x);
            addSupplied(1, x);
        break;
        case 6:
            addSupplied(6, x);
            addSupplied(4, x);
            addSupplied(2, x);
        break;
        case 7:
            addSupplied(7, x);
            addSupplied(6, x);
            addSupplied(5, x);
            addSupplied(4, x);
            addSupplied(3, x);
            addSupplied(2, x);
            addSupplied(1, x);
        break;
        }
        addSupplied(0, x);
    }
    printf("%i", supplied);
    return 0;
}
