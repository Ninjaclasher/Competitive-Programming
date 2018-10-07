#include <bits/stdc++.h>

using namespace std;

int a[3];
int cnt = 0;

void print()
{
    printf("Round %i: %i undefeated, %i one-loss, %i eliminated\n", cnt, a[0], a[1], a[2]);
    cnt++;
}

int main()
{
    int t;
    scanf("%i", &t);
    while (t--)
    {
        int n;
        cnt = 0;
        scanf("%i", &n);
        a[0] = n, a[1] = a[2] = 0;
        while (a[0] > 1)
        {
            print();
            a[2] += (a[1]>>1);
            a[1] -= (a[1]>>1);
            a[1] += (a[0]>>1);
            a[0] -= (a[0]>>1);
        }
        while (a[1] > 1)
        {
            print();
            a[2] += (a[1]>>1);
            a[1] -= (a[1]>>1);
        }
        if (a[0] && a[1])
        {
            print();
            a[0]--;
            a[1]++;
            print();
            a[2]++;
            a[1]--;
            print();
        }
        printf("There are %i rounds.\n", cnt-1);
        printf("\n"); 
    }
}

