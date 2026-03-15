const int MOD = 1e9 + 7;

class Node
{
public:
    Node *left;
    Node *right;
    int l;
    int r;
    int mid;
    long long v;
    long long add;
    long long mul;

    Node(int l, int r)
    {
        this->l = l;
        this->r = r;
        this->mid = (l + r) >> 1;
        this->left = nullptr;
        this->right = nullptr;
        v = 0;
        add = 0;
        mul = 1;
    }
};

class SegmentTree
{
private:
    Node *root;

public:
    SegmentTree()
    {

        root = new Node(1, 1e5 + 1);
    }

    void modifyAdd(int l, int r, int increment)
    {
        modifyAdd(l, r, increment, root);
    }

    void modifyAdd(int l, int r, int increment, Node *node)
    {
        if (l > r)
            return;

        if (node->l >= l && node->r <= r)
        {

            node->v = (node->v + (long long)(node->r - node->l + 1) * increment) % MOD;
            node->add = (node->add + increment) % MOD;
            return;
        }

        pushdown(node);

        if (l <= node->mid)
        {
            modifyAdd(l, r, increment, node->left);
        }
        if (r > node->mid)
        {
            modifyAdd(l, r, increment, node->right);
        }

        pushup(node);
    }

    void modifyMul(int l, int r, int multiplier)
    {
        modifyMul(l, r, multiplier, root);
    }

    void modifyMul(int l, int r, int multiplier, Node *node)
    {
        if (l > r)
            return;

        if (node->l >= l && node->r <= r)
        {

            node->v = (node->v * multiplier) % MOD;
            node->add = (node->add * multiplier) % MOD;
            node->mul = (node->mul * multiplier) % MOD;
            return;
        }

        pushdown(node);

        if (l <= node->mid)
        {
            modifyMul(l, r, multiplier, node->left);
        }
        if (r > node->mid)
        {
            modifyMul(l, r, multiplier, node->right);
        }

        pushup(node);
    }

    int query(int l, int r)
    {
        return query(l, r, root);
    }

    int query(int l, int r, Node *node)
    {
        if (l > r)
            return 0;

        if (node->l >= l && node->r <= r)
        {
            return node->v;
        }

        pushdown(node);

        int result = 0;

        if (l <= node->mid)
        {
            result = (result + query(l, r, node->left)) % MOD;
        }

        if (r > node->mid)
        {
            result = (result + query(l, r, node->right)) % MOD;
        }

        return result;
    }

    void pushup(Node *node)
    {
        node->v = (node->left->v + node->right->v) % MOD;
    }

    void pushdown(Node *node)
    {

        if (!node->left)
        {
            node->left = new Node(node->l, node->mid);
        }
        if (!node->right)
        {
            node->right = new Node(node->mid + 1, node->r);
        }

        if (node->add != 0 || node->mul != 1)
        {
            long long addTag = node->add;
            long long mulTag = node->mul;
            Node *leftChild = node->left;
            Node *rightChild = node->right;

            leftChild->v = (leftChild->v * mulTag + (leftChild->r - leftChild->l + 1) * addTag) % MOD;
            leftChild->add = (leftChild->add * mulTag + addTag) % MOD;
            leftChild->mul = (leftChild->mul * mulTag) % MOD;

            rightChild->v = (rightChild->v * mulTag + (rightChild->r - rightChild->l + 1) * addTag) % MOD;
            rightChild->add = (rightChild->add * mulTag + addTag) % MOD;
            rightChild->mul = (rightChild->mul * mulTag) % MOD;

            node->add = 0;
            node->mul = 1;
        }
    }
};

class Fancy
{
private:
    int n;
    SegmentTree *tree;

public:
    Fancy()
    {
        n = 0;
        tree = new SegmentTree();
    }

    void append(int val)
    {
        ++n;

        tree->modifyAdd(n, n, val);
    }

    void addAll(int inc)
    {
        tree->modifyAdd(1, n, inc);
    }

    void multAll(int m)
    {
        tree->modifyMul(1, n, m);
    }

    int getIndex(int idx)
    {

        if (idx >= n)
        {
            return -1;
        }

        return tree->query(idx + 1, idx + 1);
    }
};