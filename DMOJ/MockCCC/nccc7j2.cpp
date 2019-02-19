#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<char> arr(7);
    for (auto &x : arr)
        scanf(" %c", &x);
    char prev = 0;
    int cnt = 0;
    for (int x = 0; x < arr.size(); x++)
    {
        if (arr[x] == 'J' && prev != 'J')
            cnt++;
        prev = arr[x];
    }
    printf("%i\n", cnt);
}
