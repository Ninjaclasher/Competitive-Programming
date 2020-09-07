#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i", &n);
    vector<int> arr(n);
    for (auto &x : arr)
        scanf("%i", &x);
    sort(arr.begin(), arr.end());
    int cnt = 0, cur_sum = 0;
    for (auto &x : arr)
    {
        if (x >= cur_sum)
        {
            cur_sum += x;
            cnt++;
        }
    }
    printf("%i\n", cnt);
}
