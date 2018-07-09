#include <stdio.h>

int* quickSort(int *arr, int left, int right) {
      int i = left, j = right;
      int tmp;
      int pivot = arr[(left + right) / 2];

      while (i <= j)
      {
            while (arr[i] < pivot)
                  i++;
            while (arr[j] > pivot)
                  j--;
            if (i <= j)
            {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }
      };

      if (left < j)
            quickSort(arr, left, j);
      if (i < right)
            quickSort(arr, i, right);

    return arr;
}

int *b = new int [100001], *c = new int [100001];

int main()
{
    int a, aa, bb, countB = 0, countC = 0;
    scanf("%i", &a);
    for (int d = 0; d < a; d++)
        scanf("%i", &b[d]);
    for (int d = 0; d < a; d++)
        scanf("%i", &c[d]);

    b = quickSort(b, 0, a-1);
    c = quickSort(c, 0, a-1);
    aa = a, bb = a;
    for (int e = a; e > 0; e--)
    {
        for (int f = aa; f > 0; f--)
        {
            if (b[e-1] > c[f-1])
            {
                aa = f-1;
                countB++;
                break;
            }
        }
        for (int f = bb; f > 0; f--)
        {
            if (c[e-1] > b[f-1])
            {
                bb = f-1;
                countC++;
                break;
            }
        }
    }

    printf("%i\n%i", countB, countC);
    return 0;
}
