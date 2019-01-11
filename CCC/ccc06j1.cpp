#include <bits/stdc++.h>

using namespace std;

int main()
{
    int arr[4][4] = {
        {461, 431, 420, 0},
        {100, 57, 70, 0},
        {130, 160, 118, 0},
        {167, 266, 75, 0},
    };
    int cnt = 0;
    for (int x = 0; x < 4; x++)
    {
        int a;
        scanf("%i", &a);
        cnt += arr[x][a-1];
    }
    printf("Your total Calorie count is %i.\n", cnt);
}
