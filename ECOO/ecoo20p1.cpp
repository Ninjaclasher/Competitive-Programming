#include <bits/stdc++.h>

using namespace std;

int convert(string &s)
{
    if (s == "C") return 0;
    else if (s == "C#") return 1;
    else if (s == "D") return 2;
    else if (s == "D#") return 3;
    else if (s == "E") return 4;
    else if (s == "F") return 5;
    else if (s == "F#") return 6;
    else if (s == "G") return 7;
    else if (s == "G#") return 8;
    else if (s == "A") return 9;
    else if (s == "A#") return 10;
    else if (s == "B") return 11;
    abort();
}

int main()
{
    int t;
    scanf("%i", &t);
    while (t--)
    {
        vector<int> arr(4);
        for (auto &x : arr)
        {
            string s;
            cin>>s;
            x = convert(s);
        }
        for (int x = 0; x < 4; x++)
            arr.push_back(arr[x]);
        for (int x = 0; x < 4; x++)
        {
            for (int y = 1; y < 4; y++)
            {
                while (arr[x+y] < arr[x+y-1])
                    arr[x+y] += 12;
                int diff = (y == 1 ? 4 : 3);
                if (arr[x+y] - arr[x+y-1] != diff)
                    goto BAD;
            }
            switch(x)
            {
                case 0: printf("root\n"); break;
                case 1: printf("third\n"); break;
                case 2: printf("second\n"); break;
                case 3: printf("first\n"); break;
            }
            goto GOOD;
BAD:;
        }
        printf("invalid\n");
GOOD:;
    }
}
