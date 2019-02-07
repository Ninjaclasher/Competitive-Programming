#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i", &n);
    vector<string> arr(n);
    for (auto &x : arr)
    {
        do
            getline(cin, x);
        while (x.empty());
    }
    for (int x = 1; x < n-1; x++)
    {
        if (arr[x] == "Bessarion")
        {
            if (arr[x-1] == "Bayview" && arr[x+1] == "Leslie")
                return 0 * printf("Y\n");
            if (arr[x+1] == "Bayview" && arr[x-1] == "Leslie")
                return 0 * printf("Y\n");
        }
    }
    printf("N\n");
}
