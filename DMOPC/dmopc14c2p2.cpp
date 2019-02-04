#include <bits/stdc++.h>

using namespace std;

int main()
{
    int l;
    scanf("%i", &l);
    int cur = 0;
    vector<int> ll;
    string s;
    cin>>s;
    for (int x = 0; x < l; x++)
    {
        if (s[x] == 'X')
        {
            if (cur)
                ll.push_back(cur);
            cur = 0;
        }
        else
            cur++;
    }
    if (cur)
        ll.push_back(cur);
    printf("%i\n", ll.size());
    for (auto &x : ll)
    {
        while (x--)
            printf("O");
        printf("\n");
    }
}
