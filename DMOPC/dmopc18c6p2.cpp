#include <bits/stdc++.h>

using namespace std;

void rotate(vector<int> &arr, vector<int> p)
{
    int tmp = arr[p[0]];
    for (int x = 0; x < p.size()-1; x++)
        arr[p[x]] = arr[p[x+1]];
    arr[p.back()] = tmp;
}

vector<int> fin(4);
vector<int> ORIENT = {1, 2, 3};
vector<int> FD = {0, 1, 2};
vector<int> SD = {0, 1, 3};

bool test(vector<int> arr, vector<int> &p)
{
    rotate(arr, p);
    return arr == fin;
}

bool chk(vector<int> &arr)
{
    if (arr == fin)
        return true;
    for (int x = 0; x < 4; x++)
    {
        for (int y = 0; y < 4; y++)
        {
            for (int z = 0; z < 4; z++)
            {
                if (x == y || y == z || z == x)
                    continue;
                vector<int> cur = arr;
                rotate(cur, vector<int>{x, y, z});
                for (int a = 0; a < 5; a++)
                {
                    if (arr[0] == fin[0])
                        break;
                    rotate(cur, ORIENT);
                }
                if (test(cur, FD))
                    return true;
                if (test(cur, SD))
                    return true;
            }
        }
    }
    return false;
}

int main()
{
    map<string,int> mp;
    int cc = 0;
    string a;
    vector<int> arr(4);
    for (auto &x : arr)
    {
        cin>>a;
        if (!mp[a])
            mp[a] = ++cc;
        x = cc;
    }
    for (auto &x : fin)
    {
        cin>>a;
        x = mp[a];
        if (!x)
            goto NO;
    }
    if (chk(arr))
        goto NO;
    //swap 2 to simulate a reflection
    for (int x = 0; x < 4; x++)
    {
        for (int y = 0; y < 4; y++)
        {
            if (x == y)
                continue;
            swap(arr[x],arr[y]);
            if (chk(arr))
                goto YES;
            swap(arr[x],arr[y]);
        }
    }
NO:;
    return 0 * printf("NO\n");
YES:;
    return 0 * printf("YES\n");
}
