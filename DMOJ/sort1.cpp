#include <bits/stdc++.h>

int main()
{
    int n, tmp;
    scanf("%i", &n);
    int arr[n];
    for (int x = 0; x < n; x++)
    {
        scanf("%i", &arr[x]);
        printf("%i ", arr[x]);
    }
    printf("\n");
    for (int z = 0; z < n-1; z++)
    {
        for (int x = 0; x < n-1; x++)
        {
            if (arr[x] > arr[x+1])
            {
                tmp = arr[x+1];
                arr[x+1] = arr[x];
                arr[x] = tmp;
                for (int y = 0; y < n; y++)
                    printf("%i ", arr[y]);
                printf("\n");
            }
        }
    }
    return 0;
}
