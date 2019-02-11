#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i", &n);
    vector<int> arr(n);
    for (auto &x : arr)
        scanf("%i", &x);
    vector<int> cop = arr;
    vector<int> mov;
    for (int x = 0; x < n-1; x++)
    {
        if (arr[x])
        {
            mov.push_back(x+2);
            arr[x] ^= 1;
            arr[x+1] ^= 1;
            if (x+2 < n)
                arr[x+2] ^= 1;
        }
    }
    if (!arr.back())
    {
        printf("%lu\n", mov.size());
        for (auto &x : mov)
            printf("%i\n", x);
        return 0;
    }
    mov.clear();
    arr = cop;
    mov.push_back(1);
    arr[0] ^= 1;
    arr[1] ^= 1;
    for (int x = 0; x < n-1; x++)
    {
        if (arr[x])
        {
            mov.push_back(x+2);
            arr[x] ^= 1;
            arr[x+1] ^= 1;
            if (x+2 < n)
                arr[x+2] ^= 1;
        }
    }
    if (!arr.back())
    {
        printf("%lu\n", mov.size());
        for (auto &x : mov)
            printf("%i\n", x);
        return 0;
    }
}
