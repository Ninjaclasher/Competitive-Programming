#include <bits/stdc++.h>

using namespace std;

int main()
{
    string a, b;
    do getline(cin, a); while (a.empty());
    do getline(cin, b); while (b.empty());
    vector<int> freq(26);
    for (auto &x : a)
        if (x ^ ' ')
            freq[x-'A']++;
    for (auto &x : b)
        if (x ^ ' ')
            freq[x-'A']--;
    for (auto &x : freq)
        if (x)
            return 0 * printf("Is not an anagram.\n");
    printf("Is an anagram.\n");
}

