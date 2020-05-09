#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    int cur = 0, cnt = 0;
    int arr[3];
    scanf("%i%i%i%i", &n, &arr[0], &arr[1], &arr[2]);
    while (n)
    {
        cur %= 3;
        arr[cur]++;
        switch (cur)
        {
            case 0:
                if (arr[0]%35 == 0)
                    n += 30;
            break;
            case 1:
                if (arr[1]%100 == 0)
                    n += 60;
            break;
            case 2:
                if (arr[2]%10 == 0)
                    n += 9;
            break;
        }
        n--;
        cur++;
        cnt++;
    }
    printf("Martha plays %i times before going broke.\n", cnt);
}
