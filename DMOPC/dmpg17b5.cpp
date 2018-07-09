#include <stdio.h>

int *t = new int[1000000];
int *w = new int [1000000];

void quickSort(int left, int right) {
      int i = left, j = right;
      int tmp;
      int pivot = w[(left + right) / 2];

      while (i <= j)
      {
            while (w[i] < pivot)
                  i++;
            while (w[j] > pivot)
                  j--;
            if (i <= j)
            {
                  tmp = t[i];
                  t[i] = t[j];
                  t[j] = tmp;
                  tmp = w[i];
                  w[i] = w[j];
                  w[j] = tmp;
                  i++;
                  j--;
            }
      };

      if (left < j)
            quickSort(left, j);
      if (i < right)
            quickSort(i, right);
}

int main()
{
    int n, q, a, m;
    scanf("%i", &n);
    for (int x = 0; x < n; x++)
        scanf("%i%i", &t[x], &w[x]);
    quickSort(0, n-1);
    scanf("%i", &q);
    for (int x = 0; x < q; x++)
    {
        m = 0;
        scanf("%i", &a);
        for (int y = n-1; y >= 0; y--)
        {
            if (t[y] <= a)
            {
                m=w[y];
                break;
            }
        }
        printf("%i\n", m);
    }
    return 0;
}
