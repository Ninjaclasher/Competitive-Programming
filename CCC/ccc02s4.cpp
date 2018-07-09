#include <bits/stdc++.h>

using namespace std;

vector<string> toString;
vector<int> weight, best, group, lines;

int main()
{
    int m, q, pTime, e = 0, o = 0;
    string pName;
    scanf("%i%i", &m, &q);
    int best[q+1] = {0}, group[q+1] = {0};
    for (int x = 0; x < q; x++)
    {
        cin >> pName;
        scanf("%i", &pTime);
        weight.push_back(pTime);
        toString.push_back(pName);
    }
    for (int x = 1; x <= q; x++)
        best[x] = INT_MAX, group[x] = -1;
    for (int x = 0; x <= q; x++)
    {
        int cur = 0;
        for (int y = 1; y <= m && x + y <= q; y++)
        {
            cur = max(cur, weight[x + y - 1]);
            if (best[x] + cur < best[x + y])
            {
                best[x + y] = best[x] + cur;
                group[x + y] = y;
            }
        }
    }
    printf("Total Time: %i\n", best[q]);
    int l = q;
    while (group[l])
    {
        lines.push_back(group[l]);
        e++;
        l -= group[l];
    }

    for (int x = e - 1; x >= 0; x--)
    {
        for (int y = 0; y < lines[x]; y++)
            cout << toString[o++] << " ";
        printf("\n");
    }
}
