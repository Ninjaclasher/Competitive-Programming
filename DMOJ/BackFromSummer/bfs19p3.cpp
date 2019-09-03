#include <bits/stdc++.h>

using namespace std;

vector<int> freq(26);

int main()
{
    int l, k;
    string s;
    cin>>s>>l>>k;
    assert(1 <= s.length() && s.length() <= 100000);
    assert(0 <= l && l <= s.length());
    assert(0 <= k && k <= s.length());
    if (l + k >= s.length())
        return 0 * printf("0\n");
    for (auto &x : s)
        freq[x - 'a']++;
    for (int x = 0; x < l; x++)
        freq[s[x] - 'a']--;
    long long mi = LONG_MAX;
    for (int x = l; x <= s.length(); x++)
    {
        vector<int> arr = freq;
        sort(arr.rbegin(), arr.rend());
        arr.push_back(0);
        long long cur = 0;
        int bound = 0;
        for (int y = 1; y < arr.size(); y++)
        {
            cur += (arr[y-1] - arr[y]) * y;
            bound = arr[y];
            if (cur > k)
            {
                int over = cur - k;
                bound += over / y;
                int left = over % y;
                for (int z = 0; z < y; z++)
                    arr[z] = bound + (z < left);
                if (left)
                    bound++;
                break;
            }
        }
        long long ans = 0;
        if (bound)
            for (auto &y : arr)
                ans += (long long)y * y;
        mi = min(mi, ans);
        if (x < s.length())
            freq[s[x] - 'a']--;
        if (x-l < s.length())
            freq[s[x-l] - 'a']++;
    }
    printf("%lli\n", mi);
}
