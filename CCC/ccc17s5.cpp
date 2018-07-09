#include <bits/stdc++.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int getPos(int actualPos, pair<int,int> &relativePos)
{
    return (actualPos-relativePos.first+relativePos.second)%relativePos.second;
}

struct block
{
    int begin, end, sum;
};

int main()
{
    int n, m, q, a, b, t;
    scan (n); scan(m); scan(q);
    int root = floor(sqrt(n)); //block size
    int numBlocks = ceil(static_cast<double>(n)/root);
    vector<block> blocks (numBlocks);
    vector<int> belongs (n), position(n);
    vector<vector<pair<int,int>>> init (m+1);
    vector<pair<int,int>> pointer (m+1);

    vector<vector<int>> lastStation(m+1, vector<int>(numBlocks, -1));
    vector<int> blockPos (n, 0);

    for (int x = 0; x < n; x++)
        scan(belongs[x]); //get subway line
    for (int x = 0, cc = 0; x < n; x += root, cc++)
    {
        int sum = 0;
        for (int y = x; y < min(n, x + root); y++)
        {
            scan(a);//get num of people at station initially
            position[y] = init[belongs[y]].size();
            init[belongs[y]].push_back(make_pair(a, y));
            lastStation[belongs[y]][cc] = y;
            blockPos[y] = cc;
            sum += a;
        }
        blocks[cc] = {x, min(n-1, x + root - 1), sum};//set block
    }
    blocks.push_back({INT_MAX, INT_MAX, 0});//indicate end of block vector
    for (int x = 0; x < init.size(); x++)
        pointer[x] = make_pair(0, init[x].size());//initialize num of rotations
    while (q--)
    {
        scan(t); scan(a);
        if (t == 1)
        {
            scan(b);
            a--, b--;
            int sum = 0, x = 0;
            while (blocks[x].end < a) x++;//if not in range
            if (blocks[x].begin < a && blocks[x].end > b)
                for (int z = a; z <= b; z++)
                    sum += init[belongs[z]][getPos(position[z], pointer[belongs[z]])].first;
            else
            {
                if (blocks[x].begin < a) //if partially in range at beginning
                {
                    for (int z = a; z <= blocks[x].end; z++)
                        sum += init[belongs[z]][getPos(position[z], pointer[belongs[z]])].first;
                    x++;
                }
                while (blocks[x].end <= b) //if fully in range
                    sum += blocks[x++].sum;
                if (blocks[x].begin <= b) //if partially in range at end
                    for (int z = blocks[x].begin; z <= b; z++)
                        sum += init[belongs[z]][getPos(position[z], pointer[belongs[z]])].first;
            }
            printf("%i\n", sum);
        }
        else
        {
            for (int x = 0; x < lastStation[a].size(); x++)
            {
                int &tmp = lastStation[a][x];
                if (tmp != -1)
                {
                    int sub = init[a][getPos(position[tmp], pointer[a])].first;
                    blocks[x].sum -= sub;
                    blocks[blockPos[init[a][(position[tmp]+1)%pointer[a].second].second]].sum += sub;
                }
            }
            pointer[a].first++;
            pointer[a].first %= pointer[a].second;
        }
    }
}
