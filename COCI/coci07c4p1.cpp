#include <bits/stdc++.h>

using namespace std;

void run(int a, int b, int c, int d, int p)
{
    int cnt = 0;
    if (p%(a+b) <= a && p%(a+b) != 0)
        cnt++;
    if (p%(c+d) <= c && p%(c+d) != 0)
        cnt++;
    switch(cnt)
    {
        case 0:
            printf("none");
            break;
        case 1:
            printf("one");
            break;
        case 2:
            printf("both");
            break;
    }
    printf("\n");
}

int main()
{
    int a, b, c, d, p, m, g;
    scanf("%i%i%i%i%i%i%i", &a, &b, &c, &d, &p, &m, &g);
    run(a, b, c, d, p);
    run(a, b, c, d, m);
    run(a, b, c, d, g);
}
