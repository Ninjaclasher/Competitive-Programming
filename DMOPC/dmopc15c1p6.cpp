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
    SegmentTree(const std::vector<Tstored>&, std::function<Tstored(Tstored, Tstored)>);
    void update(Tsize, Tstored);
    void update(Tsize, Tsize, Tstored);
    Tstored query (Tsize, Tsize);
    void reset();

private:
    Tstored construct(const std::vector<Tstored>&, Tsize, Tsize, Tsize);
    void updateRangeUtil(Tsize, Tsize, Tsize, Tsize, Tsize, Tstored);
    std::vector<Tstored> tree;
    std::vector<Tstored> lazy;
    std::function<Tstored(Tstored, Tstored)> run;
};

template <typename Tstored, typename Tsize>
SegmentTree<Tstored,Tsize>::SegmentTree(const std::vector<Tstored>& originalArray, std::function<Tstored(Tstored, Tstored)> aa) 
    : DataStructure<Tsize>(originalArray.size()), run(aa)
{
    Tsize nElements = 2*pow(2, ceil(log2(this->numElements)))-1;
    tree.resize(nElements);
    lazy.resize(nElements);
    construct(originalArray, 0, this->numElements-1, 0);
} 

template <typename Tstored, typename Tsize>
void SegmentTree<Tstored,Tsize>::reset()
{
    fill(tree.begin(), tree.end(), 0);
    fill(lazy.begin(), lazy.end(), 0);
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
        if (lazy[v])
        {
            tree[v] += (e-s+1)*lazy[v];
            if (s != e)
            {
                lazy[2*v+1] += lazy[v];
                lazy[2*v+2] += lazy[v];
            }
            lazy[v] = 0;
        }
        if (qs <= s && qe >= e)
            result = run(result, tree[v]);
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
        if (lazy[v])
        {
            tree[v] += (e-s+1)*lazy[v];
            if (s != e)
            {
                lazy[2*v+1] += lazy[v];
                lazy[2*v+2] += lazy[v];
            }
            lazy[v] = 0;
        }
        if (index >= s && index <= e)
        {
            if (v == index)
                tree[v] += val;
            else
                tree[v] = run(val, tree[v]);
            if (s != e)
            {
                Tsize mid = s + (e -s)/2;
                buf.push(std::make_pair(2*v+1, std::make_pair(s, mid)));
                buf.push(std::make_pair(2*v+2, std::make_pair(mid+1, e)));
            }
        }
    } 
}

template <typename Tstored, typename Tsize>
void SegmentTree<Tstored,Tsize>::updateRangeUtil(Tsize node, Tsize start, Tsize end, Tsize l, Tsize r, Tstored val)
{
    if(lazy[node])
    { 
        tree[node] += (end - start + 1) * lazy[node];  
        if(start != end)
        {
            lazy[node*2+1] += lazy[node];  
            lazy[node*2+2] += lazy[node];       
        }
        lazy[node] = 0;                                 
    }
    if(start > end || start > r || end < l)          
        return;
    if(start >= l && end <= r)
    {
        tree[node] += (end - start + 1) * val;
        if(start != end)
        {
            lazy[node*2+1] += val;
            lazy[node*2+2] += val;
        }
        return;
    }
    int mid = (start + end) / 2;
    updateRangeUtil(node*2+1, start, mid, l, r, val); 
    updateRangeUtil(node*2+2, mid + 1, end, l, r, val); 
    tree[node] = tree[node*2+1] + tree[node*2+2];  
}

template <typename Tstored, typename Tsize>
void SegmentTree<Tstored, Tsize>::update(Tsize us, Tsize ue, Tstored val)
{
    //lazy[0] += val;
    updateRangeUtil(0, 0, this->numElements-1, us, ue, val);

    /*std::queue<std::pair<Tsize,std::pair<Tsize,Tsize>>> buf;
    buf.push(std::make_pair(0, std::make_pair(0, this->numElements-1)));

    while (!buf.empty())
    {
        Tsize v = buf.front().first, s = buf.front().second.first, e = buf.front().second.second;
        buf.pop();
        if (lazy[v])
        {
            tree[v] += (e-s+1)*lazy[v];
            if (s != e)
            {
                lazy[2*v+1] += lazy[v];
                lazy[2*v+2] += lazy[v];
            }
            lazy[v] = 0;
        }

        if (s>e || s>ue || e<us)
            continue;
     
        if (s>=us && e<=ue)
        {
            tree[v] += (e-s+1)*val;
     
            if (s != e)
            {
                lazy[2*v+1] += val;
                lazy[2*v+2] += val;
            }
            continue;
        }
        Tsize mid = s + (e -s)/2;
        buf.push(std::make_pair(2*v+1, std::make_pair(s, mid)));
        buf.push(std::make_pair(2*v+2, std::make_pair(mid+1, e)));
       // tree[si] = tree[si*2+1] + tree[si*2+2];
    }*/
}

template <typename Tstored, typename Tsize>
Tstored SegmentTree<Tstored,Tsize>::construct(const std::vector<Tstored>& arr, Tsize s, Tsize e, Tsize v)
{
    if (s == e)
    {
        tree[v] = arr[s];
        return arr[s];
    }
 
    Tsize mid = s + (e -s)/2;
    tree[v] = run(construct(arr, s, mid, v*2+1), construct(arr, mid+1, e, v*2+2));
    return tree[v];
}

int main()
{
    int m, n, q, a, b, c, t;
    scanf("%i%i%i", &m, &n, &q);
    vector<long long> arr (n);
    for (int x = 0; x < n; x++)
        scanf("%lli", &arr[x]);
    SegmentTree<long long,int> gg (arr, plus<long long>());
    while (q--)
    {
        scanf("%i%i%i", &t, &a, &b);
        a--; b--;
        if (t == 1)
        {
            scanf("%i", &c);
            //for (int x = a; x <= b; x++)
                //gg.update(x, c);
            gg.update(a, b, c);
        }
        else
            printf("%lli\n", gg.query(a, b)%m);
    }
    return 0;
}
