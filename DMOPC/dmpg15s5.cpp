#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, a, b, w, h, cnt = 0;
    scanf("%i%i", &n, &m);
    vector<vector<bool>> board (n+3);
    for (auto &x : board)
        x.resize(n+3);
    while (m--)
    {
        scanf("%i%i%i%i", &a, &b, &w, &h);
        a++;b++;
        board[a][b] = !board[a][b];
        board[a+w][b+h] = !board[a+w][b+h];
        board[a+w][b] = !board[a+w][b];
        board[a][b+h] = !board[a][b+h];
    }
    for (int x = 1; x <= n+1; x++)
    {
        bool cur = false;
        for (int y = 1; y <= n+1; y++)
        {
            cur ^= board[x][y];
            if (cur) 
                cnt++;
            if (board[x][y])
                board[x+1][y] = !board[x+1][y];
        }

    }
    printf("%i\n", cnt);
    return 0;
}
