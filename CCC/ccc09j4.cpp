#include <bits/stdc++.h>

using namespace std;

void dots(int cnt)
{
    while (cnt--)
        printf(".");
}

int main()
{
    int n;
    scanf("%i", &n);
    vector<string> a({"WELCOME", "TO", "CCC", "GOOD", "LUCK", "TODAY"});
    int i = 0, c = 0;
    for (; i < a.size();)
    {
        int j = i;
        while (i < a.size() && a[i].length() + c + (i-j) <= n) c += a[i].length(), i++;
        int spaces = (i-j-1);
        if (spaces <= 0)
        {
            cout<<a[j];
            dots(n-a[j].length());
            if (j == i) i++;
            c = 0;
            printf("\n");
            continue;
        }
        int dps = (n-c)/spaces;
        int dms = (n-c)%spaces;
        for (int x = j; x < i-1; x++)
        {
            cout<<a[x];
            dots(dps + (x-j < dms));
        }
        cout<<a[i-1];
        c = 0;
        printf("\n");
    }
}
