#include <bits/stdc++.h>

using namespace std;

template <typename Tstored, typename Tsize>
class BinaryIndexTree
{
public:
    BinaryIndexTree(const Tsize);
    Tstored range (Tsize, Tsize, Tsize);
    void update (Tsize, Tsize, Tsize, const Tstored);

private:
    std::vector<vector<vector<Tstored>>> tree;
    const Tsize numElements;
};

template <typename Tstored, typename Tsize>
BinaryIndexTree<Tstored, Tsize>::BinaryIndexTree (const Tsize n) : numElements (n)
{
    tree.resize(this->numElements);
    for (auto &x : tree)
    {
        x.resize(this->numElements);
        for (auto &y : x)
            y.resize(this->numElements, 0);
    }
}

template <typename Tstored, typename Tsize>
Tstored BinaryIndexTree<Tstored, Tsize>::range (Tsize index1, Tsize index2, Tsize index3)
{
    Tstored sum = 0;
    for (; index1 > 0; index1 -= index1&-index1)
        for (Tsize i2 = index2; i2 > 0; i2 -= i2&-i2)
            for (Tsize i3 = index3; i3 > 0; i3 -= i3&-i3)
                sum+=tree[index1-1][i2-1][i3-1];
    return sum;
}

template <typename Tstored, typename Tsize>
void BinaryIndexTree<Tstored, Tsize>::update (Tsize index1, Tsize index2, Tsize index3, const Tstored val)
{
    for (; index1 <= this->numElements; index1 += index1&-index1)
        for (Tsize i2 = index2; i2 <= this->numElements; i2 += i2&-i2)
            for (Tsize i3 = index3; i3 <= this->numElements; i3 += i3&-i3)
                tree[index1-1][i2-1][i3-1] += val;
}

int main()
{
    int n, q, a, b, c, aa, bb, cc;
    long long tot = 0;
    char t;
    scanf("%i%i", &n, &q);
    BinaryIndexTree<long long, long long> bit (n);
    vector<vector<vector<int>>> bef (n+1);
    for (auto &x : bef)
    {
        x.resize(n+1);
        for (auto &y : x)
            y.resize(n+1, 0);
    }
    while (q--)
    {
        scanf(" %c%i%i%i", &t, &a, &b, &c);
        if (t == 'C')
        {
            scanf("%i", &aa);
            bit.update(a, b, c, aa-bef[a][b][c]);
            bef[a][b][c] = aa;
        }
        else
        {
            scanf("%i%i%i", &aa, &bb, &cc);
            tot += bit.range(aa, bb, cc) - bit.range(a-1, bb, cc) - bit.range(aa, b-1, cc) - bit.range(aa, bb, c-1) + bit.range(aa, b-1, c-1) + bit.range(a-1, b-1, cc) + bit.range(a-1, bb, c-1) - bit.range(a-1, b-1, c-1);
            if (a-1 < 0 || b-1 < 0 || c-1<0)
                return 1;
        }
    }
    printf("%lli", tot);
}
