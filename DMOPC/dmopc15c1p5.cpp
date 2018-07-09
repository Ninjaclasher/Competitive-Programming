#include <stdio.h>

#define max(a,b) a>b ? a : b

int prefixSum[251][251];

int main()
{
    int w, h, n, maxSum = 0;
    scanf("%i%i%i", &w, &h, &n);
    for (int y = 1; y <= h; y++)
    {
        for (int x = 1; x <= w; x++)
        {
            scanf("%i", &prefixSum[x][y]);
            prefixSum[x][y] += prefixSum[x-1][y] + prefixSum[x][y-1] - prefixSum[x-1][y-1];
            for (int yy = 1; yy <= y; yy++)
                maxSum = max(maxSum, prefixSum[x][y] - prefixSum[x][y-yy] - prefixSum[max(x-(n/yy),0)][y] + prefixSum[max(x-(n/yy),0)][y-yy]);
        }
    }
    printf("%i", maxSum);
    return 0;
}
