#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i", &n);
    vector<int> a(n), b(n);
    for (auto &x : a)
        scanf("%i", &x);
    for (auto &x : b)
        scanf("%i", &x);
    int arr[2] = {0,0};
    for (int x = 0; x < n; x++)
    {
        if (a[x] > b[x])
            arr[0]++;
        else if (a[x] < b[x])
            arr[1]++;
    }
    printf("%i %i\n", arr[0], arr[1]);
    if (arr[0] > arr[1])
        printf("Xyene\n");
    else if (arr[0] < arr[1])
        printf("FatalEagle\n");
    else
        printf("Tie\n");
}
