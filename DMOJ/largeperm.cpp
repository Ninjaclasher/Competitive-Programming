#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int n, k;
    scanf("%i%i", &n, &k);
    vector<int> a(100005), b(100005);
    for (int x = 1; x <= n; x++)
    {
        scanf("%i", &a[x]);
        b[a[x]] = x;
    }
    for (int x = n; x > 0 && k; x--)
        if (b[x] ^ (n-x+1))
            swap(a[b[x]], a[n-x+1]), swap(b[a[b[x]]], b[a[n-x+1]]), k--;
    for (int x = 1; x <= n; x++)
        printf("%i ", a[x]);
    return 0;
}
