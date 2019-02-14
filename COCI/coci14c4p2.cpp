#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, a;
    scanf("%i", &n);
    map<int,int> mp;
    while (n--)
    {
        scanf("%i", &a);
        mp[a]++;
    }
    vector<pair<int,int>> arr;
    for (auto &x : mp)
        arr.push_back(x);
    int l = 0, r = arr.size()-1;
    long long lsum = 0, rsum = 0;
    while (r-l >= 2)
    {
        if (lsum < rsum)
        {
            lsum += arr[l].second;
            arr[l+1].second += arr[l].second;
            l++;
        }
        else
        {
            rsum += arr[r].second;
            arr[r-1].second += arr[r].second;
            r--;
        }
    }
    if (lsum <= rsum)
        printf("Slavko\n");
    else
        printf("Mirko\n");
    printf("%i %i\n", arr[l].first, arr[r].first);
}
