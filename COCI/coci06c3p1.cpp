#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n = 9;
    vector<int> arr(n);
    for (auto &x : arr)
        scanf("%i", &x);
    sort(arr.begin(), arr.end());
    do
    {
        int s = 0;
        for (int x = 0; x < 7; x++)
            s += arr[x];
        if (s == 100)
        {
            for (int x = 0; x < 7; x++)
                printf("%i\n", arr[x]);
            break;
        }
    }
    while (next_permutation(arr.begin(), arr.end()));
}
