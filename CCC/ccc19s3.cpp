#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

int n = 3;

const int MAX = 100000000;
const int MIN = -100000000;

static inline bool GOOD(vector<vector<int>> &arr)
{
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < n; y++)
            if (arr[x][y] == INT_MAX)
                return false;
        if (arr[x][2] != arr[x][1]+arr[x][1]-arr[x][0])
            return false;
    }
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < n; y++)
            if (arr[y][x] == INT_MAX)
                return false;
        if (arr[2][x] != arr[1][x]+arr[1][x]-arr[0][x])
            return false;
    }
    return true;
}

bool FILL(vector<vector<int>> &arr)
{
    vector<int> dx(n, INT_MAX), dy(n, INT_MAX);
    bool did = false;
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < n; y++)
        {
            for (int z = y+1; z < n; z++)
            {
                if (arr[x][y] < INT_MAX && arr[x][z] < INT_MAX)
                    dx[x] = (arr[x][y]-arr[x][z])/(y-z);
            }
        }
    }
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < n; y++)
        {
            for (int z = y+1; z < n; z++)
            {
                if (arr[y][x] < INT_MAX && arr[z][x] < INT_MAX)
                    dy[x] = (arr[y][x]-arr[z][x])/(y-z);
            }
        }
    }
    for (int x = 0; x < n; x++)
    {
        if (dx[x] < INT_MAX)
        {
            for (int y = 0; y < n; y++)
            {
                if (arr[x][y] == INT_MAX)
                {
                    for (int z = 0; z < n; z++)
                        if (arr[x][z] < INT_MAX)
                            arr[x][y] = arr[x][z] + (y-z) * dx[x], did = true;
                }
            }
        }
    }
    for (int x = 0; x < n; x++)
    {
        if (dy[x] < INT_MAX)
        {
            for (int y = 0; y < n; y++)
            {
                if (arr[y][x] == INT_MAX)
                {
                    for (int z = 0; z < n; z++)
                        if (arr[z][x] < INT_MAX)
                            arr[y][x] = arr[z][x] + (y-z) * dy[x], did = true;
                }
            }
        }
    }
    return did;
}

void chk(vector<vector<int>> &arr)
{
    for (auto &x : arr)
        for (auto &y : x)
            if (y == INT_MAX)
                return;
    for (auto &x : arr)
    {
        for (auto &y : x)
            printf("%i ", y);
        printf("\n");
    }
    exit(0);
}

int main()
{
    string a;
    vector<vector<int>> arr(n, vector<int>(n));
    int cnt = 0;
    for (auto &x : arr)
    {
        for (auto &y : x)
        {
            cin>>a;
            if (a == "X")
                y = INT_MAX, cnt++;
            else
                y = stoi(a);
        }
    }
/*    if (cnt > 3)
    {
        cout<<"14 20 26"<<endl;
        cout<<"18 18 18"<<endl;
        cout<<"22 16 10"<<endl;
        return 0;
    }*/
    if (cnt >= 8)
    {
        int v = 0;
        for (auto &x : arr)
            for (auto &y : x)
                if (y < INT_MAX)
                    v = y;
        cout<<v<<" "<<v<<" "<<v<<endl;
        cout<<v<<" "<<v<<" "<<v<<endl;
        cout<<v<<" "<<v<<" "<<v<<endl;
        return 0;
    }
    if (cnt == 7)
    {
        vector<pair<int,int>> pos;
        for (int x = 0; x < n; x++)
        {
            for (int y = 0; y < n; y++)
            {
                if (arr[x][y] < INT_MAX)
                    pos.push_back({x, y});
            }
        }
        if (pos[0].first == pos[1].first)
        {
            while(FILL(arr));
            for (int x = 0; x < n; x++)
            {
                int v = arr[pos[0].first][x];
                for (int y = 0; y < n; y++)
                    arr[y][x] = v;
            }
        }
        else if (pos[0].second == pos[1].second)
        {
            while(FILL(arr));
            for (int x = 0; x < n; x++)
            {
                int v = arr[x][pos[0].second];
                for (int y = 0; y < n; y++)
                    arr[x][y] = v;
            }
        }
        else
        {
            auto co = arr;
            for (int x = 0; x < n; x++)
            {
                int v = INT_MAX;
                for (int y = 0; y < n; y++)
                    if (co[x][y] < INT_MAX)
                        v = co[x][y];
                if (v == INT_MAX)
                    continue;
                for (int y = 0; y < n; y++)
                    co[x][y] = v;
            }
            while(FILL(co));
            if (GOOD(co))
                chk(co);
            for (int x = 0; x < n; x++)
            {
                int v = INT_MAX;
                for (int y = 0; y < n; y++)
                    if (arr[y][x] < INT_MAX)
                        v = arr[y][x];
                if (v == INT_MAX)
                    continue;
                for (int y = 0; y < n; y++)
                    arr[y][x] = v;
            }
            while(FILL(arr));

        }
        chk(arr);
        while(1);
    }
    if (cnt == 6)
    {
        for (int x = 0; x < n; x++)
        {
            for (int y = 0; y < n; y++)
            {
                if (arr[x][y] == INT_MAX)
                    continue;
                bool onColumn = true, onRow = true;
                for (int z = 0; z < n; z++)
                    onColumn &= arr[z][y] < INT_MAX;
                for (int z = 0; z < n; z++)
                    onRow &= arr[x][z] < INT_MAX;
                if (onColumn)
                {
                    for (int xx = 0; xx < n; xx++)
                        for (int yy = 0; yy < n; yy++)
                            arr[xx][yy] = arr[xx][y];
                    chk(arr);
                }
                else if (onRow)
                {
                    for (int xx = 0; xx < n; xx++)
                        for (int yy = 0; yy < n; yy++)
                            arr[xx][yy] = arr[x][yy];
                    chk(arr);
                }
            }
        }
    }
    while(FILL(arr));
    chk(arr);
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < n; y++)
        {
            if (arr[x][y] == INT_MAX)
            {
                for (int z = MIN; z <= MAX; z++)
                {
                    auto co = arr;
                    co[x][y] = z;
                    while(FILL(co));
                    if (GOOD(co))
                        chk(co);
                }
                abort();
            }
        }
    }
}
