#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n, m, t, l, f;
    scanf("%lli%lli%lli", &n, &m, &t);
    vector<long long> micros (n, 0);
    priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>>> people;
    for (int x = 0; x < m; x++)
    {
        scanf("%lli%lli", &l, &f);
        people.push(make_pair(l, f));
    }
    while (!people.empty())
    {
        l = people.top().first, f = people.top().second;
        people.pop();
        auto it = upper_bound(micros.begin(), micros.end(), l);
        if (it != micros.begin())
            it--;
        long long v = *it;
        if (l-micros[0] >= t)
        {
            printf("%lli", micros[0]);
            return 0;
        }
        micros[it-micros.begin()] = max(static_cast<long long>(l),v)+f;
        sort(micros.begin(), micros.end());
    }
    printf("%lli", micros[0]);

    return 0;
}
