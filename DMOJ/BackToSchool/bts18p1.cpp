#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s, t;
    getline(cin, s);
    getline(cin, t);
    assert(s.length() == t.length());
    int k, c = 0;
    scanf("%i", &k);
    for (int x = 0; x < s.length(); x++)
    {
        if ((s[x] == ' ') ^ (t[x] == ' '))
            goto NO;
        else if (s[x] != t[x])
            c++;
    }
    if (c <= k)
        goto YES;
    else
        goto NO;
NO:
    printf("No plagiarism\n");
    return 0;
YES:
    printf("Plagiarized\n");
    return 0;
}

