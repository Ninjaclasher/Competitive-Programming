#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int r, c, a;
    scanf("%i%i", &r, &c);
    vector<int> rr(r), aa, bb;
    for (auto &x : rr)
    {
        for (int y = c-1; y >= 0; y--)
        {
            scanf("%i", &a);
            x += pow(2,y) * a;
        }
    }
    aa.push_back(rr[0]);
    for (int x = 1; x < r; x++)
    {
        bb.clear();
        bb.push_back(rr[x]);
        for (auto &y : aa)
        {
            int ss = y^bb[0];
            if (find(bb.begin(),bb.end(),ss) == bb.end())
                bb.push_back(ss);
        }
        aa = bb;
    }
    printf("%i", bb.size());
    return 0;
}
