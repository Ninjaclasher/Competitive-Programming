#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    long long sum = 0;
    scanf("%i", &n);
    vector<pair<int,int>> arr(n);
    for (auto &x : arr)
        scanf("%i%i", &x.first, &x.second);
    for (int x = 0; x < n; x++)
    {
        sum += arr[x].first * arr[(x+1)%n].second;
        sum -= arr[x].second * arr[(x+1)%n].first;
    }
    printf("%i\n", (abs(sum)+1)/2);
}
