#include <bits/stdc++.h>

using namespace std;

int main()
{
    string t, s;
    cin>>t>>s;
    for (int x = 0; x <= t.length()-s.length(); x++)
    {
        for (int y = 0; y < s.length(); y++)
        {
            bool good = true;
            for (int z = 0; good && z < s.length(); z++)
                good &= s[(y + z) % s.length()] == t[x + z];
            if (good)
                return 0 * printf("yes\n");
        }
    }
    printf("no\n");
}
