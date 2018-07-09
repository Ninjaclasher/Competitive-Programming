#include <bits/stdc++.h>

using namespace std;

class SegmentTree
{
public:
    SegmentTree(const vector<unsigned int>&);
    unsigned int query(unsigned int, unsigned int);
    void update(unsigned int, unsigned int);

private:
    unsigned int construct(const vector<unsigned int>&, unsigned int, unsigned int, unsigned int);
    unsigned int updateUtil(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
    vector<unsigned int> tree;
    unsigned int numElements;
};

SegmentTree::SegmentTree(const vector<unsigned int>& originalArray) : numElements(originalArray.size())
{
    unsigned int nElements = 2*pow(2, ceil(log2(this->numElements)))-1;
    tree.resize(nElements);
    construct(originalArray, 0, this->numElements-1, 0);
}

unsigned int SegmentTree::query(unsigned int qs, unsigned int qe)
{
    unsigned int result = 4294967295;
    queue<pair<unsigned int,pair<unsigned int,unsigned int>>> buf;
    buf.push(make_pair(0, make_pair(0, this->numElements-1)));

    while (!buf.empty())
    {
        unsigned int v = buf.front().first, s = buf.front().second.first, e = buf.front().second.second;
        buf.pop();
        if (qs <= s && qe >= e)
            result &= tree[v];
        else if (s <= qe && e >= qs)
        {
            unsigned int mid = s + (e -s)/2;
            buf.push(make_pair(2*v+1, make_pair(s, mid)));
            buf.push(make_pair(2*v+2, make_pair(mid+1, e)));
        }
    }
    return result;
}

unsigned int SegmentTree::updateUtil(unsigned int s, unsigned int e, unsigned int v, unsigned int i, unsigned int val)
{
    if (i < s || i > e) return tree[v];
    if (s == e) return tree[v] = val;
    unsigned int mid = s+ (e-s) / 2;
    return tree[v] = updateUtil(s, mid, v*2+1, i, val) & updateUtil(mid+1, e, v*2+2, i, val);
}


void SegmentTree::update(unsigned int index, unsigned int val)
{
    updateUtil(0, numElements-1, 0, index, val);
}

unsigned int SegmentTree::construct(const vector<unsigned int>& arr, unsigned int s, unsigned int e, unsigned int v)
{
    if (s == e) return tree[v] = arr[s];
    unsigned int mid = s + (e -s)/2;
    tree[v] = construct(arr, s, mid, v*2+1) & construct(arr, mid+1, e, v*2+2);
    return tree[v];
}

int main()
{
    int n, q;
    unsigned int a, b, c;
    char t;
    scanf("%i%i", &n, &q);
    vector<unsigned int> arr (n);
    for (auto &x : arr)
        scanf("%u", &x);
    SegmentTree st (arr);
    while (q--)
    {
        scanf(" %c%u%u", &t, &a, &b);
        a--;
        if (t == 'U')
            st.update(a, b);
        else
        {
            scanf("%u", &c);
            b--;
            printf("%u\n", (c & st.query(a, b)));
        }
    }
}
