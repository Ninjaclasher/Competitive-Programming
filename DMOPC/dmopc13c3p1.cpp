#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, myNum;
    scanf("%i%i", &n, &m);
    int mm [m];
    char name [m][31];
    for (int x = 0; x < m; x++)
    {
        scanf("%i%i", &n, &mm[x]);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        for (int y = 0; y < 31; y++)
        {
            cin >> noskipws >> name[x][y];
            if (name[x][y] == '\n')
                break;
        }
    }
    scanf("%i", &myNum);
    for (int x = 0; x < m; x++)
    {
        if (mm[x] == myNum)
        {
            for (int y = 0; y < 31; y++)
            {
                printf("%c", name[x][y]);
                if (name[x][y] == '\n')
                    break;
            }
        }
    }
    return 0;
}
