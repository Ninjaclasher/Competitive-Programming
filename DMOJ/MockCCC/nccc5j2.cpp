#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i", &n);
    vector<int> arr(12);
    int a;
    while (n--)
    {
        scanf("%i", &a);
        arr[a]++;
    }
    int ma = 1;
    for (int x = 2; x <= 10; x++)
        if (arr[ma] < arr[x])
            ma = x;
    printf("%i\n", ma);
}
