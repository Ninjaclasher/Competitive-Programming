#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    scanf("%i%i", &n, &k);
    if (n < k)
        return 0 * printf("WRONGANSWER\n");
    string a;
    cin>>a;
    for (int y = k; y >= 0; y--)
    {
        string b = a.substr(0, y);
        vector<int> freq(26);
        for (int x = y; x < n; x++)
            freq[a[x]-'a']++;
        for (int x = 0; x < 26; x++)
            if (freq[x] == k-y)
                while (b.size() < n)
                    b += (x+'a');
        if (b.size() == n)
            return 0 * printf("%s\n", b.c_str());
    }
    return 0 * printf("WRONGANSWER\n");
}

