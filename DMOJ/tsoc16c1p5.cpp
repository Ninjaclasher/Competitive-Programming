#include <bits/stdc++.h>

using namespace std;

void nth_permutation(vector<int> &arr, long long n)
{
    vector<long long> fact(arr.size());
    vector<bool> vis(arr.size());
    for (long long x = 1; n; x++)
    {
        fact[arr.size()-x] = n%x;
        n /= x;
    }
    for (int x = 0; x < arr.size(); x++)
    {
        for (int y = 0, c = -1; y < arr.size(); y++)
        {
            if (!vis[y])
            {
                c++;
                if (c == fact[x])
                {
                    vis[y] = 1, arr[x] = y+1;
                    break;
                }
            }
        }       
    }
}

int main()
{
    int n, q;
    long long a;
    scanf("%i%i", &n, &q);
    vector<int> arr(n);
    while (q--)
    {
        scanf("%lli", &a);
        nth_permutation(arr, a);
        for (auto &x : arr)
            printf("%i ", x);
        printf("\n");
    }

}

