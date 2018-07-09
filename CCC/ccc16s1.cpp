#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int s = 0;
    vector<int> freq(26);
    string a;
    do getline(cin, a); while (a.empty());
    for (auto &t : a)
        freq[t-'a']++;
    do getline(cin, a); while (a.empty());
    for (auto &t : a)
    {
    
        if (t == '*') s++;
        else freq[t-'a']--;
    }
    for (auto &x : freq)
    {
        if (x < 0) return 0 * printf("N");
        s -= x;
    }
    if (s) printf("N");
    else printf("A");
    return 0;
}
