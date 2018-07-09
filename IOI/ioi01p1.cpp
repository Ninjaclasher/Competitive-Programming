#include <bits/stdc++.h>

using namespace std;

template <typename Tstored, typename Tsize>
class BinaryIndexTree
{
    static_assert(std::is_integral<Tstored>::value, "Integer type required.");
    static_assert(std::is_arithmetic<Tstored>::value, "Arithmetic is not supported with supplied type.");
public:
    void init(const Tsize n);
    Tstored range (Tsize, Tsize);
    void update (Tsize, Tsize, const Tstored);

private:
    std::vector<vector<Tstored>> tree;
    Tsize numElements;

};

template <typename Tstored, typename Tsize>
void BinaryIndexTree<Tstored, Tsize>::init (const Tsize n)
{
    numElements = n;
    tree.resize(this->numElements);
    for (auto &x : tree)
        x.resize(this->numElements, 0);
}

template <typename Tstored, typename Tsize>
Tstored BinaryIndexTree<Tstored, Tsize>::range (Tsize index, Tsize index2)
{
    Tstored sum = 0;
    for (; index > 0; index -= index&-index)
        for (Tsize a = index2; a > 0; a -= a&-a)
        sum+=tree[index-1][a-1];
    return sum;
}

template <typename Tstored, typename Tsize>
void BinaryIndexTree<Tstored, Tsize>::update (Tsize index, Tsize index2, const Tstored val)
{
    for (; index <= this->numElements; index += index&-index)
        for (Tsize a = index2; a <= this->numElements; a += a&-a)
        tree[index-1][a-1] += val;
}

int main()
{
    int n, a, b, c, d;
    BinaryIndexTree<unsigned int, int> tr;
    while (true)
    {
        scanf("%i", &n);
        switch(n)
        {
            case 0:
                scanf("%i", &a);
                tr.init(a);
            break;
            case 1:
                scanf("%i%i%i", &a, &b, &c);
                tr.update(a+1, b+1, c);
            break;
            case 2:
                scanf("%i%i%i%i", &a, &b, &c, &d);
                printf("%u\n", tr.range(c+1, d+1)-tr.range(c+1, b)-tr.range(a, d+1)+tr.range(a, b));
            break;
            case 3:
                return 0;
        }
    }
    return 0;
}
