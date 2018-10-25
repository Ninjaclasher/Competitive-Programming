#include <bits/stdc++.h>

using namespace std;

string guess_sequence(int N)
{
    vector<char> pos;
    string cur = "";
    if (press("AB"))
    {
        if (press("A"))
            cur = "A", pos = {'B', 'X', 'Y'};
        else
            cur = "B", pos = {'A', 'X', 'Y'};
    }
    else
    {
        if (press("X"))
            cur = "X", pos = {'A', 'B', 'Y'};
        else
            cur = "Y", pos = {'A', 'B', 'X'};
    }
    if (N == 1)
        return cur;
    while (cur.length() < N-1)
    {
        string guess;
        guess += cur+pos[1];
        for (int x = 0; x < 3; x++)
            guess += cur+pos[2]+pos[x];
        int ret = press(guess);
        if (ret-cur.length() == 0)
            cur += pos[0];
        else if (ret-cur.length() == 1)
            cur += pos[1];
        else if (ret-cur.length() == 2)
            cur += pos[2];
        else
            abort();
    }
    if (press(cur+pos[0]) == N)
        cur += pos[0];
    else if (press(cur+pos[1]) == N)
        cur += pos[1];
    else
        cur += pos[2];
    return cur;
}

