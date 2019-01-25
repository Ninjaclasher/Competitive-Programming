#include <bits/stdc++.h>

using namespace std;

struct food
{
    char c;
    int cnt;
    friend bool operator<(food &a, food &b)
    {
        if (a.cnt > b.cnt)
            return true;
        else if (a.cnt == b.cnt)
        {
            if (a.c == 'D')
                return true;
            else if (a.c == 'B' && b.c != 'D')
                return true;
            else if (a.c == 'S' && b.c == 'R')
                return true;
        }
        return false;
    }
};

int main()
{
    map<char,int> mp;
    int n;
    scanf("%i", &n);
    for (int x = 0; x < n; x++)
    {
        string na;
        do getline(cin, na); while (na.empty());
        mp[na[0]]++;
    }
    vector<food> arr;
    for (auto &x : mp)
        arr.push_back({x.first, x.second});
    sort(arr.begin(), arr.end());
    for (auto &x : arr)
    {
        if (x.c == 'D')
            printf("Deluxe Tuna Bitz ");
        else if (x.c == 'B')
            printf("Bonito Bitz ");
        else if (x.c == 'S')
            printf("Sashimi ");
        else
            printf("Ritzy Bitz ");
        printf("%i\n", x.cnt);
    }
}
