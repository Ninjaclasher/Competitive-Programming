#include <bits/stdc++.h>

using namespace std;

int arr[2];

int main()
{
    map<string,int> mp;
    mp["true"] = 1;
    int q;
    scanf("%i", &q);
    while (q--)
    {
        int t;
        string s;
        scanf("%i", &t);
        if (t != 4)
            cin>>s;
        if (t == 1)
        {
            if (arr[mp[s]])
                printf("false\n");
            else
                printf("true\n");
            arr[mp[s]] = 1;
        }
        else if (t == 2)
        {
            if (arr[mp[s]])
                printf("true\n");
            else
                printf("false\n");
            arr[mp[s]] = 0;
        }
        else if (t == 3)
        {
            if (!mp[s])
            {
                if (!arr[mp[s]])
                    printf("-1\n");
                else
                    printf("0\n");
            }
            else
            {
                if (!arr[mp[s]])
                    printf("-1\n");
                else if (arr[!mp[s]])
                    printf("1\n");
                else
                    printf("0\n");
            }
        }
        else
        {
            if (arr[0])
                printf("false ");
            if (arr[1])
                printf("true");
            printf("\n");
        }
    }
}

