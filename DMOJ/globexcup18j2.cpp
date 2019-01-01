#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i", &n);
    long long sum = 0;
    vector<long long> arr(n);
    for (auto &x : arr)
        scanf("%lli", &x), sum += x;
    sort(arr.begin(), arr.end());
    int mid = n/2;
    if (!(n&1))
        mid--;
    if (arr[mid]*n > sum)
        printf("Winnie should take the risk\n");
    else
        printf("That's too risky\n");
}
