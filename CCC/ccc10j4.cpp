#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, a, b, pattern;
    vector<int> diff(20);
    scanf("%i", &n);
    while (n)
    {
        scanf("%i", &a);
        if (n == 1)
            printf("0\n");
        else
        {
            for (int x = 1; x < n; x++)
            {
                scanf("%i", &b);
                diff[x] = b-a;
                a = b;
            }
            pattern = 1;
            while (true)
            {
                for (a = 1; a+pattern < n && diff[a] == diff[a+pattern]; a++);
                if (a + pattern >= n)
                    break;
                pattern++;
            }
            printf("%i\n", pattern);
        }
        scanf("%i", &n);
    }
}
