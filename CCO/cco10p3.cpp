#include <bits/stdc++.h>

using namespace std;

struct node
{
    pair<int,int> data;
    node* ch[2];
    int height;
    int num;
};

class AVLTree
{
public:
    ~AVLTree();
    AVLTree() { root = NULL; }

    void insert (pair<int,int> x) { root = insert(x, root); sum(root);}
    void remove (int x) { root = remove(x, root); if (root != NULL) sum(root);}
    pair<int,int> nthElement(int x) { return nthElement(root, x); }
    friend ostream& operator<<(ostream &os, AVLTree& t)
    {
        t.print(os, t.root);
        return os;
    }

private:
    node* root;
    node* insert(pair<int,int> &, node*);
    node* singleRotate(node* &, int);
    node* doubleRotate(node* &, int);
    node* findMin(node*);
    node* findMax(node*);
    node* remove(int, node*);
    pair<int,int> nthElement(node*, int);
    void deleteTree(node*);
    inline int height(node* t) { return (t == NULL ? -1 : t->height); }
    inline int getBalance(node* t) { return (t == NULL) ? 0 : height(t->ch[0]) - height(t->ch[1]); }
    inline void sum(node *t) {t->num = 1 + (t->ch[0] == NULL ? 0 : t->ch[0]->num) + (t->ch[1] == NULL ? 0 : t->ch[1]->num);}
    void print(ostream &os, node* t);
};

AVLTree::~AVLTree()
{
    deleteTree(root);
}

void AVLTree::deleteTree(node* t)
{
    if (t != NULL)
    {
        deleteTree(t->ch[1]);
        deleteTree(t->ch[0]);
        delete t;
    }
}

node* AVLTree::insert(pair<int,int> &x, node* t)
{
    if(t == NULL)
    {
        t = new node;
        t->data = x;
        t->height = 0;
        t->num = 1;
        t->ch[0] = t->ch[1] = NULL;
    }
    else if (x.first < t->data.first)
    {
        t->ch[0] = insert(x, t->ch[0]);
        sum(t);
    }
    else if (x.first > t->data.first)
    {
        t->ch[1] = insert(x, t->ch[1]);
        sum(t);
    }
    sum(t);
    t->height = max(height(t->ch[0]), height(t->ch[1]))+1;
    return t;
}

//0 = left rotate, 1 = right rotate
node* AVLTree::singleRotate(node* &t, int d)
{
    node* u = t->ch[!d];
    t->ch[!d] = u->ch[d];
    u->ch[d] = t;
    t->height = max(height(t->ch[0]), height(t->ch[1]))+1;    
    u->height = max(height(d ? u->ch[0] : t->ch[1]), t->height)+1;
    sum(t);
    sum(u);
    return u;
}

node* AVLTree::doubleRotate(node* &t, int d)
{
    t->ch[!d] = singleRotate(t->ch[!d], !d);
    return singleRotate(t, d);
}

node* AVLTree::findMin(node* t)
{
    return (t == NULL || t->ch[0] == NULL) ? t : findMin (t->ch[0]);
}

node* AVLTree::findMax(node* t)
{
    return (t == NULL || t->ch[1] == NULL) ? t : findMax (t->ch[1]);
}

node* AVLTree::remove(int x, node* t)
{
    node* temp;
    if(t == NULL) return NULL;
    else if(x < t->data.first) t->ch[0] = remove(x, t->ch[0]);
    else if(x > t->data.first) t->ch[1] = remove(x, t->ch[1]);
    else if(t->ch[0] && t->ch[1])
    {
        temp = findMin(t->ch[1]);
        t->data = temp->data;
        t->ch[1] = remove(t->data.first, t->ch[1]);
        sum(t);
    }
    else
    {
        temp = t;
        if (t->ch[0] == NULL) t = t->ch[1];
        else if (t->ch[1] == NULL) t = t->ch[0];
        delete temp;
    }
    if (t == NULL) return NULL;
    sum(t);
    t->height = max(height(t->ch[0]), height(t->ch[1]))+1;
    return t;
}

pair<int,int> AVLTree::nthElement(node *t, int x)
{
    if (t == NULL)
        abort();
    int c = (t->ch[1] == NULL ? 0 : t->ch[1]->num);
    if (c+1 == x)
        return t->data;
    if (c >= x)
        return nthElement(t->ch[1], x);
    else
        return nthElement(t->ch[0], x-c-1);
}

void AVLTree::print(ostream &os, node* t)
{
    if (t == NULL) return;
    print(os, t->ch[0]);
    os << t->data.first << " " << t->num <<"\n";
    print(os, t->ch[1]);
}


int main()
{
    AVLTree st;
    int n, a, b;
    char t;
    scanf("%i", &n);
    vector<int> pe(1000007);
    while(n--)
    {
        scanf(" %c%i", &t, &a);
        switch(t)
        {
            case 'N':
                scanf("%i", &b);
                pe[a] = b;
                st.insert(make_pair(b,a));
            break;
            case 'M':
                scanf("%i", &b);
                st.remove(pe[a]);
                pe[a] = b;
                st.insert(make_pair(b,a));
            break;
            case 'Q':
                printf("%i\n", st.nthElement(a).second);
            break;
            case 'P':
                cout << st <<"\n";
        }
    }
}
