#include <bits/stdc++.h>

using namespace std;

template <typename T>
class DataStructure
{
    static_assert(std::is_integral<T>::value, "Integer type required.");
    static_assert(std::is_arithmetic<T>::value, "Arithmetic is not supported with supplied type.");
public:
    virtual void reset() = 0;
    DataStructure(const T);
    virtual T size() const;

private:

protected:
    const T numElements;
};

template <typename T>
DataStructure<T>::DataStructure(const T n) : numElements(n) {}

template <typename T>
T DataStructure<T>::size() const
{
    return numElements;
}

template <typename Tstored, typename Tsize>
class SegmentTree : public DataStructure<Tsize>
{
    static_assert(std::is_integral<Tstored>::value, "Integer type required.");
    static_assert(std::is_arithmetic<Tstored>::value, "Arithmetic is not supported with supplied type.");
public:
    SegmentTree(const std::vector<Tstored>&);
    pair<Tstored, Tsize> query (Tsize, Tsize);
    void reset();

private:
    pair<Tstored, Tsize> construct(const std::vector<Tstored>&, Tsize, Tsize, Tsize);
    std::vector<pair<Tstored, Tsize>> tree;
};

template <typename Tstored, typename Tsize>
SegmentTree<Tstored,Tsize>::SegmentTree(const std::vector<Tstored>& originalArray)
    : DataStructure<Tsize>(originalArray.size())
{
    Tsize nElements = 2*pow(2, ceil(log2(this->numElements)))-1;
    tree.resize(nElements);
    construct(originalArray, 0, this->numElements-1, 0);
} 

template <typename Tstored, typename Tsize>
void SegmentTree<Tstored,Tsize>::reset()
{
}

template <typename Tstored, typename Tsize>
pair<Tstored, Tsize> SegmentTree<Tstored,Tsize>::query(Tsize qs, Tsize qe)
{
    pair<Tstored, Tsize> result = make_pair(INT_MAX, 0);
    std::queue<std::pair<Tsize,std::pair<Tsize,Tsize>>> buf;
    buf.push(std::make_pair(0, std::make_pair(0, this->numElements-1)));

    while (!buf.empty())
    {
        Tsize v = buf.front().first, s = buf.front().second.first, e = buf.front().second.second;
        buf.pop();
        if (qs <= s && qe >= e)
            result = min(result, tree[v]);
        else if (s <= qe && e >= qs)
        {
            Tsize mid = s + (e -s)/2;
            buf.push(std::make_pair(2*v+1, std::make_pair(s, mid)));
            buf.push(std::make_pair(2*v+2, std::make_pair(mid+1, e)));
        }
    }
    return result;
}

template <typename Tstored, typename Tsize>
pair<Tstored, Tsize> SegmentTree<Tstored,Tsize>::construct(const std::vector<Tstored>& arr, Tsize s, Tsize e, Tsize v)
{
    if (s == e)
    {
        tree[v] = make_pair(arr[s], s);
        return tree[v];
    }
 
    Tsize mid = s + (e -s)/2;
    tree[v] = min(construct(arr, s, mid, v*2+1), construct(arr, mid+1, e, v*2+2));
    return tree[v];
}

int main()
{
    vector<int> timeHere, timeDry(200005);
    int n, m, j, a, b;
    scanf("%i%i%i", &n, &m, &j);
    timeHere.resize(n+j+1, INT_MAX);
    timeHere[0] = 0;
    fill(timeDry.begin(), timeDry.begin()+n+1, INT_MAX);
    for (int x = 0; x < m; x++)
    {
        scanf("%i%i", &a, &b);
        timeDry[a] = b;
    }
    SegmentTree<int,int> qq (timeDry);
    for (int x = 0; x < n; x++)
    {
        pair<int,int> mm = qq.query(x+1, x+j);
        if (max(timeHere[x], mm.first) < timeHere[mm.second])
            timeHere[mm.second] = max (timeHere[x], mm.first);
    }
    int tt = INT_MAX;
    for (int x = 0; x <= j; x++)
        tt = min (timeHere[n+x], tt);
    printf("%i\n", tt == INT_MAX ? -1 : tt);
    return 0;

}
