#include <bits/stdc++.h>

using namespace std;

int arr[100][100];
int gten[100];

string pad(int x, int y)
{
    if (arr[x][y] < 10 && gten[y])
        return " " + to_string(arr[x][y]);
    else
        return to_string(arr[x][y]);
}


int main()
{
    int t = 1;
    while (t--)
    {
        int l, u, mixx = INT_MAX, maxx = INT_MIN, miyy = INT_MAX, mayy = INT_MIN;
        scanf("%i%i", &l, &u);
        for (int x = 0; x < 100; x++)
            for (int y = 0; y < 100; y++)
                arr[x][y] = 0;
        int xx = 49, yy = 51;
        //1 = right, 2 = left, 3 = up, 4 = down
        int dir = 2;
        int chk[5] = {0, 3, 4, 2, 1};
        vector<pair<int,int>> face({{100, 100},{0, 1}, {0, -1}, {-1, 0}, {1, 0}});
        for (int x = l; x <= u; x++)
        {
            arr[xx][yy] = x;
            if (!arr[xx+face[chk[dir]].first][yy+face[chk[dir]].second])
                dir = chk[dir];
            mixx = min(mixx, xx);
            maxx = max(maxx, xx);
            miyy = min(miyy, yy);
            mayy = max(mayy, yy);
            xx += face[dir].first;
            yy += face[dir].second;
        }
        for (int y = 0; y < 100; y++)
            for (int x = 0; x < 100 && !gten[y]; x++)
                gten[y] |= (arr[x][y] > 9);
        for (int x = mixx; x <= maxx; x++)
        {
            for (int y = miyy; y <= mayy; y++)
            {
                if (!arr[x][y])
                {
                    cout<<" ";
                    if (gten[y])
                        cout<<" ";
                }
                else
                    cout<<pad(x, y);
                if (y != mayy)
                    cout<<" ";
            }
            cout<<"\n";
        }
        if (t > 0)
            cout<<"\n";
    }
}
