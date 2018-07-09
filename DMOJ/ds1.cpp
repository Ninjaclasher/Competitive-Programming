#include <bits/stdc++.h>

using namespace std;

template <typename T>
class binary_indexed_tree
{
    static_assert(is_integral<T>::value, "Integer type required.");
    static_assert(is_arithmetic<T>::value, "Arithmetic is not supported with supplied type.");
public:
    binary_indexed_tree(const unsigned int sz);
    binary_indexed_tree(const vector<T> &arr);
    void update(unsigned int idx, const T val);
    T query(unsigned int idx);
    T query(unsigned int lower_idx, unsigned int upper_idx);
    inline unsigned int size() { return bit.size() - 1;};
private:
    inline unsigned int LSB(unsigned int i) { return i&-i; }
    vector<T> bit;
};

template <typename T>
binary_indexed_tree<T>::binary_indexed_tree(const unsigned int sz)
{
    bit.resize(sz+1);
}

template <typename T>
binary_indexed_tree<T>::binary_indexed_tree(const vector<T> &arr)
{
    bit.resize(arr.size());
    for (int x = 1; x < arr.size(); x++)
    {
        bit[x] += arr[x];
        if (x+LSB(x) < arr.size())
            bit[x+LSB(x)] += bit[x];
    }
}

template <typename T>
void binary_indexed_tree<T>::update(unsigned int idx, const T val)
{
    for (; idx < bit.size(); idx += LSB(idx))
        bit[idx] += val;
}

template <typename T>
T binary_indexed_tree<T>::query(unsigned int idx)
{
    T ret = 0;
    for (; idx > 0; idx -= LSB(idx))
        ret += bit[idx];
    return ret;
}

template <typename T>
T binary_indexed_tree<T>::query(unsigned int lower_idx, unsigned int upper_idx)
{
    return query(upper_idx) - query(lower_idx - 1);
}


int main()
{
    int n, m, a, b;
    scanf("%i%i", &n, &m);
    vector<long long> arr(n+1);
    binary_indexed_tree<int> val(200000);
    for (int x = 1; x <= n; x++)
        scanf("%lli", &arr[x]), val.update(arr[x], 1);
    binary_indexed_tree<long long> bit(arr);
    char t;
    while (m--)
    {
        scanf(" %c%i", &t, &a);
        switch(t)
        {
            case 'C':
                scanf("%i", &b);
                val.update(arr[a], -1);
                val.update(b, 1);
                bit.update(a, b-arr[a]);
                arr[a] = b;
            break;
            case 'S':
                scanf("%i", &b);
                printf("%lli\n", bit.query(a, b));
            break;
            case 'Q':
                printf("%i\n", val.query(a));
            break;
        }
    }
}
