#include <bits/stdc++.h>

using namespace std;

template <typename T>
class BinaryIndexTree
{
public:
    BinaryIndexTree(const unsigned int);
    T query(unsigned int);
    T query(unsigned int, unsigned int);
    T flip(int, unsigned int, unsigned int);
    void update(unsigned int, const T);
    unsigned int numElements;
private:
    vector<T> tree;
};

template <typename T>
BinaryIndexTree<T>::BinaryIndexTree(const unsigned int n) : numElements (n)
{
    tree.resize(this->numElements, 0);
}

template <typename T>
T BinaryIndexTree<T>::query(unsigned int index)
{
    T sum = 0;
    for (; index > 0; index -= index&-index)
        sum+=tree[index];
    return sum;
}

template <typename T>
T BinaryIndexTree<T>::query(unsigned int us, unsigned int ue)
{
    return query (ue) - query(us-1);
}

template <typename T>
void BinaryIndexTree<T>::update(unsigned int index, const T val)
{
    for (; index <= this->numElements; index += index&-index)
        tree[index] += val;
}

template <typename T>
T BinaryIndexTree<T>::flip(int t, unsigned int l, unsigned int h)
{
    return t ? (query(1, l) - query(h, numElements)) : (query(h, numElements) - query(1, l));
}

int main()
{
    long long n, z;
    vector<BinaryIndexTree<long long>> bit(3, BinaryIndexTree<long long>(30100)); 
    scanf("%lli", &n);
    while (n--)
    {
        scanf("%lli", &z);
        bit[2].update(z + 15005, z*z);
        bit[1].update(z + 15005, z);
        bit[0].update(z + 15005, 1);
        long double l = -15000, h = 15000, x;
        while (abs(l-h) > 0.001)
        {
            x = (l+h)/2.0;
            int hm = ceil(x)+15005, lm = floor(x)+15005;
            long double a = bit[0].flip(1, lm, hm), b = 2*bit[1].flip(0, lm, hm), c = bit[2].flip(1, lm, hm);
            (a*x*x + b*x + c < 0 ? l : h) = x;
        }
        printf("%Lf\n", x);
    }
}
