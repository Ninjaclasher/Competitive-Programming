#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i", &n);
    vector<int> arr(n);
    for (auto &x : arr)
        scanf("%i", &x);
    int cnt = 0;
    bool sorted = false;
    while (!sorted)
    {
        sorted = true;
        for (int x = 0; x < n-1; x++)
            if (arr[x] < arr[x+1])
                swap(arr[x], arr[x+1]), cnt++, sorted = false;
    }
    printf("%i\n", cnt);
}

