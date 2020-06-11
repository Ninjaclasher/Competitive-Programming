#include <bits/stdc++.h>

using namespace std;

int main()
{
    int w;
    scanf("%i", &w);
    if (w <= 26)
    {
        for (int x = 0; x < w; x++)
            cout<<(char)(x+'a')<<" ";
        cout<<endl;
        return 0;
    }
    for (char x = 'a'; x <= 'z' && w; x++, w--)
        cout<<x<<" ";

    for (char x = 'a'; x <= 'z' && w; x++)
        for (char y = 'a'; y <= 'z' && w; y++, w--)
            cout<<x<<y<<" ";

    for (char x = 'a'; x <= 'z' && w; x++)
        for (char j = 'a'; j <= 'z' && w; j++)
            for (char y = 'a'; y <= 'z' && w; y++, w--)
                cout<<x<<j<<y<<" ";    
}
