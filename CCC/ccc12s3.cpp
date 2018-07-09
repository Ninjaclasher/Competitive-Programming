#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int n, a;
    vector<pair<int,int>> freq(1002, make_pair(0,0));
    scanf("%i", &n);
    vector<int> big;
    for (int x = 0; x < n; x++)
    {
        scanf("%i", &a);
        freq[a].first++;
        freq[a].second = a;
    }
    sort(freq.rbegin(), freq.rend());
    vector<int> high = {freq[0].second};
    int ma = freq[0].first;
    int idx = 0;
    while (freq[++idx].first == ma) high.push_back(freq[idx].second);
    sort (high.begin(), high.end());
    if (high.size() == 1)
    {
        ma = abs(high[0]-freq[idx].second);
        int mm = freq[idx].first;
        while (freq[++idx].first == mm) ma = max(ma, high[0]-freq[idx].second);
        printf("%i\n", ma);
    }
    else
        printf("%i\n", abs(high.back()-high[0]));
    return 0;
}
