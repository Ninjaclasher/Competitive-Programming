#include <iostream>

using namespace std;

struct node
{
    int data;
    node* ch[2];
    int height;
    int count;
    int num;
};

class AVLTree
{
public:
    ~AVLTree();
    AVLTree() { root = NULL; }

    void insert (int x) { root = insert(x, root); sum(root);}
    void remove (int x) { root = remove(x, root, false); if (root != NULL) sum(root);}
    int firstOccur(int x) { return firstOccur(root, x); }
    int nthElement(int x) { return nthElement(root, x); }
    friend ostream& operator<<(ostream &os, AVLTree& t)
    {
        t.print(os, t.root);
        return os;
    }

private:
    node* root;
    node* insert(int, node*);
    node* singleRotate(node* &, int);
    node* doubleRotate(node* &, int);
    node* findMin(node*);
    node* findMax(node*);
    node* remove(int, node*, bool);
    int firstOccur(node*, int);
    int nthElement(node*, int);
    void deleteTree(node*);
    inline int height(node* t) { return (t == NULL ? -1 : t->height); }
    inline int getBalance(node* t) { return (t == NULL) ? 0 : height(t->ch[0]) - height(t->ch[1]); }
    inline void sum(node *t) {t->num = t->count + (t->ch[0] == NULL ? 0 : t->ch[0]->num) + (t->ch[1] == NULL ? 0 : t->ch[1]->num);}
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

node* AVLTree::insert(int x, node* t)
{
    if(t == NULL)
    {
        t = new node;
        t->data = x;
        t->height = 0;
        t->count = t->num = 1;
        t->ch[0] = t->ch[1] = NULL;
    }
    else if (x == t->data)
        (t->count)++, (t->num)++;
    else if (x < t->data)
    {
        t->ch[0] = insert(x, t->ch[0]);
        sum(t);
        if(height(t->ch[0]) - height(t->ch[1]) == 2)
        {
            if (x < t->ch[0]->data) t = singleRotate(t, 1);
            else t = doubleRotate(t, 1);
        }
    }
    else if (x > t->data)
    {
        t->ch[1] = insert(x, t->ch[1]);
        sum(t);
        if(height(t->ch[1]) - height(t->ch[0]) == 2)
        {
            if (x > t->ch[1]->data) t = singleRotate(t, 0);
            else t = doubleRotate(t, 0);
        }
    }

    t->height = max(height(t->ch[0]), height(t->ch[1]))+1;
    return t;
}

//0 = left rotate, 1 = right rotate
node* AVLTree::singleRotate(node* &t, int d)
{
    if (t == NULL || t->ch[!d] == NULL) return t;
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

node* AVLTree::remove(int x, node* t, bool clear=false)
{
    node* temp;
    if(t == NULL) return NULL;
    else if(x < t->data) t->ch[0] = remove(x, t->ch[0],clear), sum(t);
    else if(x > t->data) t->ch[1] = remove(x, t->ch[1],clear), sum(t);
    else if(t->ch[0] && t->ch[1])
    {
        if (t->count > 1)
        {
            (t->count)--;
            (t->num)--;
            return t;
        }
        temp = findMin(t->ch[1]);
        t->data = temp->data;
        t->count = temp->count;
        t->ch[1] = remove(t->data, t->ch[1],true);
        sum(t);
    }
    else
    {
        if (t->count > 1 && !clear)
        {
            (t->count)--;
            (t->num)--;
            return t;
        }
        temp = t;
        if (t->ch[0] == NULL) t = t->ch[1];
        else if (t->ch[1] == NULL) t = t->ch[0];
        delete temp;
    }
    if (t == NULL) return NULL;
    sum(t);
    t->height = max(height(t->ch[0]), height(t->ch[1]))+1;

    if (height(t->ch[0]) - height(t->ch[1]) == 2)
    {
        if (height(t->ch[0]->ch[0]) - height(t->ch[0]->ch[1]) == 1) return singleRotate(t, 0);
        else return doubleRotate(t, 0);
    }
    else if (height(t->ch[1]) - height(t->ch[0]) == 2)
    {
        if (height(t->ch[1]->ch[1]) - height(t->ch[1]->ch[0]) == 1) return singleRotate(t, 1);
        else return doubleRotate(t, 1);
    }
    return t;
}

int AVLTree::firstOccur(node* t, int x)
{
    if (t == NULL)
        return -1;
    if (x < t->data)
        return firstOccur(t->ch[0], x);
    else if (x > t->data)
    {
        int ret = firstOccur(t->ch[1], x);
        if (~ret)
            ret += (t->ch[0] == NULL ? 0 : t->ch[0]->num) + t->count;
        return ret;
    }
    return (t->ch[0] == NULL ? 0 : t->ch[0]->num) + 1;
}

int AVLTree::nthElement(node *t, int x)
{
    if (t == NULL)
        abort();
    int c = (t->ch[0] == NULL ? 0 : t->ch[0]->num);
    if (c < x && c+t->count >= x)
        return t->data;
    if (c >= x)
        return nthElement(t->ch[0], x);
    else
        return nthElement(t->ch[1], x-c-t->count);
}

void AVLTree::print(ostream &os, node* t)
{
    if (t == NULL) return;
    print(os, t->ch[0]);
    for (int i = 0; i < t->count; i++)
        os << t->data << " ";
    print(os, t->ch[1]);
}

int main()
{
    AVLTree st;
    int n, m, a, p = 0;
    char t;
    scanf("%i%i", &n, &m);
    for (int x = 0; x < n; x++)
    {
        scanf("%i", &a);
        st.insert(a);
    }
    while (m--)
    {
        scanf(" %c%i", &t, &a);
        a ^= p;
        switch(t)
        {
            case 'I':
                st.insert(a);
            break;
            case 'R':
                st.remove(a);
            break;
            case 'S':
                printf("%i\n", p = st.nthElement(a));
            break;
            case 'L':
                printf("%i\n", p = st.firstOccur(a));
            break;
        }
    }
    cout << st;
}
