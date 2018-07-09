#include <bits/stdc++.h>

using namespace std;

int main() 
{
    vector<vector<char>> grid = 
       {{'*', 'x', '*'},
        {' ', 'x', 'x'},
        {'*', ' ', '*'}};
    int k;
    scanf("%i", &k);
    for (int x = 0; x < 3; x++)
        for (int i = 0; i < k; i++, printf("\n"))
            for (int y = 0; y < 3; y++)
                for (int j = 0; j < k; j++, printf("%c", grid[x][y]));
    
    return 0;
}
