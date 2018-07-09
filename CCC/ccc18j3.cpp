#include <bits/stdc++.h>

using namespace std;

int main() 
{
    vector<int> a(4);
    for (auto &x : a)
        scanf("%i", &x);
    for (int x = 0; x < 5; x++)
    {
        vector<int> aa(5);
        for (int y = x-1; y >= 0; y--)
            aa[y] = aa[y+1]+a[y];
        for (int y = x+1; y < 5; y++)
            aa[y] = aa[y-1]+a[y-1];
        for (auto &y : aa)
            printf("%i ", y);
        printf("\n");
    }
    return 0;
}
