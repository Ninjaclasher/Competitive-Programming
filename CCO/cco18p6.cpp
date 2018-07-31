#include <bits/stdc++.h>

using namespace std;

vector<int> arr;
vector<pair<int,int>> mv;

static inline __attribute__((always_inline)) void sswap(int i, int j)
{
    if (i == j)
        return;
    if (i > j)
        swap(i, j);
    swap(arr[i], arr[j]);
    mv.push_back({i+1, j+1});
}

void merge(int l, int m, int r)
{
    if (l == r || m+1 > r || l > m)
        return;
    if (r-l == 1)
    {
        if (arr[l] > arr[r])
            sswap(l, r);
        return;
    }
    int i = l, j = m+1;
    for (int x = 0; x < (r-l+1)/2; x++)
    {
        if (i > m)
            j++;
        else if (j > r)
            i++;
        else if (arr[i] < arr[j])
            i++;
        else
            j++;
    }
    for (int x = 0; x < (m-i+1)/2; x++)
        sswap(i+x, m-x);
    --j;
    for (int x = 0; x < (j-(m+1)+1)/2; x++)
        sswap(m+1+x, j-x);
    for (int x = 0; x < (j-i+1)/2; x++)
        sswap(i+x, j-x);
    m = l+(r-l+1)/2-1;
    merge(l, i-1, m), merge(m+1, j, r);
}

void merge_sort(int l, int r)
{
    if (l > r || l == r)
        return;
    int m = l+r>>1;
    merge_sort(l, m);
    merge_sort(m+1, r);
    merge(l, m, r);
}

void run()
{
    mv.clear();
    for (auto &x : arr)
        scanf("%i", &x);
    bool sorted = true;
    for (int x = 1; x < arr.size() && sorted; x++)
        sorted &= arr[x-1] < arr[x];
    if (!sorted)
        merge_sort(0, arr.size()-1);
}

int main()
{
    int n;
    scanf("%i", &n);
    arr.resize(n);
    run();
    vector<pair<int,int>> mv1 = mv;
    run();
    printf("%i\n", mv1.size() + mv.size());
    for (auto &x : mv1)
        printf("%i %i\n", x.first, x.second);
    reverse(mv.begin(), mv.end());
    for (auto &x : mv)
        printf("%i %i\n", x.first, x.second);
}

