#include <bits/stdc++.h>

using namespace std;

int main()
{
    int arr[26][2] = {
        {1, 2},
        {2, 2},
        {3, 2},
        {1, 3},
        {2, 3},
        {3, 3},
        {1, 4},
        {2, 4},
        {3, 4},
        {1, 5},
        {2, 5},
        {3, 5},
        {1, 6},
        {2, 6},
        {3, 6},
        {1, 7},
        {2, 7},
        {3, 7},
        {4, 7},
        {1, 8},
        {2, 8},
        {3, 8},
        {1, 9},
        {2, 9},
        {3, 9},
        {4, 9},
    };
    string a;
    for (cin>>a; a != "halt"; cin>>a)
    {
        int cnt = 0;
        int prev = 0;
        for (auto &x : a)
        {
            if (arr[x-'a'][1] == prev)
                cnt += 2;
            prev = arr[x-'a'][1];
            cnt += arr[x-'a'][0];
        }
        printf("%i\n", cnt);
    }
}

