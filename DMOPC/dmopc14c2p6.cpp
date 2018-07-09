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
public:
    SegmentTree(const std::vector<Tstored>&);
    void update(Tsize, Tstored);
    Tstored query (Tsize, Tsize);
    void reset();

private:
    std::vector<Tstored> tree;
};

template <typename Tstored, typename Tsize>
SegmentTree<Tstored,Tsize>::SegmentTree(const std::vector<Tstored>& originalArray) 
    : DataStructure<Tsize>(originalArray.size())
{
    tree.resize(2*pow(2, ceil(log2(this->numElements))) - 1);
} 

template <typename Tstored, typename Tsize>
void SegmentTree<Tstored,Tsize>::reset()
{
    fill(tree.begin(), tree.end(), 0);
}

template <typename Tstored, typename Tsize>
Tstored SegmentTree<Tstored,Tsize>::query(Tsize qs, Tsize qe)
{
    Tstored result = 0;
    std::queue<std::pair<Tsize,std::pair<Tsize,Tsize>>> buf;
    buf.push(std::make_pair(0, std::make_pair(0, this->numElements-1)));

    while (!buf.empty())
    {
        Tsize v = buf.front().first, s = buf.front().second.first, e = buf.front().second.second;
        buf.pop();
        if (qs <= s && qe >= e)
            result += tree[v];
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
void SegmentTree<Tstored,Tsize>::update(Tsize index, Tstored val)
{
    std::queue<std::pair<Tsize,std::pair<Tsize,Tsize>>> buf;
    buf.push(std::make_pair(0, std::make_pair(0, this->numElements-1)));

    while (!buf.empty())
    {
        Tsize v = buf.front().first, s = buf.front().second.first, e = buf.front().second.second;
        buf.pop();
        if (index >= s && index <= e)
        {
            tree[v] += val;
            if (s != e)
            {
                Tsize mid = s + (e -s)/2;
                buf.push(std::make_pair(2*v+1, std::make_pair(s, mid)));
                buf.push(std::make_pair(2*v+2, std::make_pair(mid+1, e)));
            }
        }
    }
} 

template<typename T1,typename T2,typename T3>
struct triple 
{
    T1 first;
    T2 second;
    T3 third;
    triple() {};
    triple(const T1 &a,const T2 &b,const T3 &c) : first(a),second(b),third(c) {}
    triple(const triple<T1,T2,T3> &t) : first(t.first),second(t.second),third(t.third){}

    bool operator==(const triple<T1,T2,T3> &b) const 
        {return ((first == b.first) && (second == b.second) && (third == b.third));};
    bool operator<(const triple<T1,T2,T3> &b) const 
        {return first == b.first ? second == b.second ? third < b.third : second < b.second : first < b.first;};
    bool operator>(const triple<T1,T2,T3> &b) const 
        {return first == b.first ? second == b.second ? third > b.third : second > b.second : first > b.first;};
};

template<typename T1,typename T2,typename T3>
triple<T1,T2,T3> make_triple(T1 a, T2 b, T3 c)
{return triple<T1,T2,T3>(a, b, c);}


int main()
{
    int n, q, a, b, sz;
    scanf("%i", &n);
    vector<pair<int,int>> aa(n+1);
    vector<pair<int,triple<int,int,int>>> buf;
    SegmentTree<int,int> tr (vector<int>(n,0));
    for (int x = 0; x < n; x++)
    {
        scanf("%i", &a);
        aa[x] = make_pair(a, x);
    }
    aa[n] = make_pair(0,0);
    scanf("%i", &q);
    for (int x = 0; x < q; x++)
    {
        scanf("%i%i%i", &a, &b, &sz);
        buf.push_back(make_pair(sz, make_triple(a, b, x)));
    }
    sort(aa.rbegin(), aa.rend());
    sort(buf.begin(), buf.end());
    vector<int> ans(q);
    while (!buf.empty() && buf.back().first > aa[0].first)
    {
        buf.pop_back();
    }
    for (int x = 0; x < n; x++)
    {
        tr.update(aa[x].second, aa[x].first);
        if (aa[x].first > aa[x+1].first)
        {
            while (!buf.empty() && buf.back().first <= aa[x].first && buf.back().first > aa[x+1].first)
            {
                ans[buf.back().second.third] = tr.query(buf.back().second.first, buf.back().second.second);
                buf.pop_back();
            }
        }
    }
    for (auto &x : ans)
        printf("%i\n", x);
}
