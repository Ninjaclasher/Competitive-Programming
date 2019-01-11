#include <bits/stdc++.h>

using namespace std;

void print(int a)
{
    printf("%3i", a);
}

int main()
{
    int a, b;
    scanf("%i%i", &a, &b);
    int c = a;
    printf("Sun Mon Tue Wed Thr Fri Sat\n");
    for (int x = 1; x < c; x++)
        printf("    ");
    for (int x = 1; x <= b; x++)
    {
        print(x);
        c++;
        if (c == 8 || x == b)
        {
            printf("\n");
            c = 1;
        }
        else
            printf(" ");
    }
}

