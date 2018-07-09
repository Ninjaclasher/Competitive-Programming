#include <stdio.h>

char grid[100][100];

int main()
{
    int n, m, t, posX = 0, posY = 0, ticks = 0, direction = 0;
    scanf("%i%i%i", &n, &m, &t);
    for (int y = 0; y < m; y++)
    {
        for (int x = 0; x < n; x++)
        {
            scanf(" %c ", &grid[y][x]);
            if (grid[y][x] == 'O')
            {
                posX = x;
                posY = y;
            }
        }
    }
    while (posX >= 0 && posX < n && posY >= 0 && posY < m)
    {//0 = right, 1 = left, 2 = up, 3 = down
        switch(direction)
        {
            case 0: posX++;
            break;
            case 1: posX--;
            break;
            case 2: posY--;
            break;
            case 3: posY++;
            break;
        }
        if (direction == 0 || direction == 1)
        {
            if (grid[posY][posX] == '\\')
            {
                grid [posY][posX] = '/';
                direction = !(direction) + 2;
            }
            else if (grid[posY][posX] == '/')
            {
                grid [posY][posX]='\\';
                direction += 2;
            }
            else if (grid[posY][posX] == '|')
            {
                grid[posY][posX] = '-';
                direction = !direction;
            }
        }
        else if (direction == 2 || direction == 3)
        {
            if (grid[posY][posX] == '\\')
            {
                grid [posY][posX] = '/';
                direction = !(direction - 2);
            }
            else if (grid[posY][posX] == '/')
            {
                grid [posY][posX] = '\\';
                direction -= 2;
            }
            else if (grid[posY][posX] == '-')
            {
                grid[posY][posX] = '|';
                direction = !(direction-2) + 2;
            }
        }
        if (++ticks > t)
        {
            printf("The observer stays within the grid.");
            return 0;
        }
    };
    printf("The observer leaves the grid after %i tick(s).", ticks);
    return 0;
}
