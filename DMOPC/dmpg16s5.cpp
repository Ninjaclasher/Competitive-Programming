#include <bits/stdc++.h>

using namespace std;

int main()
{
    deque<pair<long long, long long>> q;
    int n, k; 
    long long ss = 0, tt = LONG_MIN;
    scanf("%i%i", &n, &k);
    long long arr[n*2+10];
    for(int x = 0; x < n; x++) 
    {
        scanf("%lli", &arr[x]);
        arr[n+x] = arr[x];
    }
    for(int x = 0; x < n*2; x++)
    {
        ss += arr[x];
        if(!q.empty())
        {
            while(!q.empty() && x-q.front().second > k) q.pop_front();
            tt = max(tt, ss-q.front().first);
            while(!q.empty() && q.back().first >= ss) q.pop_back();
            q.push_back(make_pair(ss, x));
        }
        else
        {
            tt = max(tt, ss);
            q.push_back(make_pair(ss, x));
        }
    }

    printf("%lli\n", tt);
    return 0;
}
