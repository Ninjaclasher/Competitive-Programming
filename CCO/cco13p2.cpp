#include <bits/stdc++.h>

using namespace std;

vector<int> numWin(2000000);
vector<pair<int,int>> tree(8000000);

class SegmentTree
{
public:
    SegmentTree(const vector<int>&);
    void update(unsigned int, int);

private:
    pair<int,int> construct(const vector<int>&, unsigned int, unsigned int, unsigned int);
    pair<int,int> update(unsigned int, int, int, int, int);
    unsigned int numElements;
};

SegmentTree::SegmentTree(const vector<int>& originalArray) : numElements(originalArray.size())
{
    construct(originalArray, 0, this->numElements-1, 0);
}
 
pair<int,int> SegmentTree::update(unsigned int index, int val, int s, int e, int v)
{
    if (index < s || index > e)
        return tree[v];
    if (s == e)
        return tree[v] = make_pair(val,index);
    else
    {
        int mid = s + (e-s)/2;
        pair<int,int> tmp = max(update(index, val, s, mid, 2*v+1), update(index, val, mid+1, e, 2*v+2));
        if (tmp.second != tree[v].second)
            numWin[tmp.second]++, numWin[tree[v].second]--;
        return tree[v] = tmp;
    }
}

void SegmentTree::update(unsigned int index, int val)
{
    update(index, val, 0, numElements-1, 0);
}

pair<int,int> SegmentTree::construct(const vector<int>& arr, unsigned int s, unsigned int e, unsigned int v)
{
    if (s == e)
        return tree[v] = make_pair(arr[s], s);
 
    unsigned int mid = s + (e -s)/2;
    tree[v] = max(construct(arr, s, mid, v*2+1), construct(arr, mid+1, e, v*2+2));
    numWin[tree[v].second]++;
    return tree[v];
}

int main()
{
    int n, m, a;
    char t;
    scanf("%i%i", &n, &m);
    vector<int> arr(1<<n);
    for (auto &x : arr)
        scanf("%i", &x);
    SegmentTree st(arr);
    while (m--)
    {
        scanf(" %c", &t);
        if (t != 'W')
            scanf("%i", &a);
        switch (t)
        {
            case 'R':
                scanf("%i", &arr[--a]);
                st.update(a, arr[a]);
            break;
            case 'W':
                printf("%i\n", tree[0].second+1);
            break;
            case 'S':
                printf("%i\n", numWin[--a]);
            break;
        }
    }
}
