#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

vector<vector<int>> cancer[MAXN];

void print_and_exit(vector<int> &arr)
{
    for (int x = 0; x < (int)arr.size(); x++)
        printf("%i%c", arr[x], x == (int)arr.size()-1 ? '\n' : ' ');
    exit(0);
}

int main()
{
    int n;
    scanf("%i", &n);
    vector<vector<int>> factors(n+1);
    for (int x = 2; x <= n; x++)
    {
        if (factors[x].empty())
            for (int y = x; y <= n; y += x)
                factors[y].push_back(x);
    }
    vector<int> arr(n);
    vector<int> suffix_min(n);
    for (auto &x : arr)
        scanf("%i", &x);
    if (n <= 2)
        print_and_exit(arr);
    suffix_min[n-1] = arr[n-1];
    for (int x = n-2; x >= 0; x--)
        suffix_min[x] = min(suffix_min[x+1], arr[x]);
    int _st = 0;
    while (_st+2 < n && arr[_st] <= suffix_min[_st+2])
        _st++;
    if (_st == n-2)
        print_and_exit(arr);
    // anything before _st do not need to be touched
    set<int> need_to_check;
    for (int y = _st; y < n; y++)
        if (arr[y] == suffix_min[_st+2])
            for (auto &z : factors[y - _st])
                need_to_check.insert(z);
    for (int y = _st; y < n; y++)
    {
        int actual_idx = y - _st;
        int cur_mi = INT_MAX;
        for (auto it = need_to_check.begin(); it != need_to_check.end();)
        {
            int mi = INT_MAX;
            if (actual_idx < *it)
            {
                // brute force checks
                for (int z = y; z < n; z += *it)
                    mi = min(mi, arr[z]);
            }
            else
            {
                if (actual_idx == *it)
                {
                    cancer[*it].resize(*it);
                    int k = (n - _st) / *it + 1;
                    for (auto &z : cancer[*it])
                        z.reserve(k);
                    for (int z = _st; z < n; z++)
                        cancer[*it][z % *it].push_back(arr[z]);
                    for (auto &z : cancer[*it])
                    {
                        sort(z.rbegin(), z.rend());
                        z.pop_back();
                    }
                }
                auto &cur = cancer[*it][y % *it];
                mi = cur.back();
                cur.pop_back();
            }
            if (mi > cur_mi)
                it = need_to_check.erase(it);
            else if (mi < cur_mi)
            {
                while (it != need_to_check.begin())
                    need_to_check.erase(need_to_check.begin());
                cur_mi = mi;
                ++it;
            }
            else
                ++it;
        }
    }
    assert(!need_to_check.empty());
    int k = *need_to_check.begin();
    vector<vector<int>> ans(k);
    for (int x = 0; x < n; x++)
        ans[x%k].push_back(arr[x]);
    for (auto &x : ans)
        sort(x.begin(), x.end());
    for (int x = 0; x < n; x++)
        arr[x] = ans[x%k][x/k];
    print_and_exit(arr);
}
