struct segmenttree
{
    int n;
    vector<int> st, lazy;
 
    void init(int _n)
    {
        this->n = _n;
        st.resize(4 * n, 0);
        lazy.resize(4 * n, 0);
    }
 
    void push(int start, int ending, int node)
    {
        if (lazy[node] != 0)
        {
            st[node] += lazy[node];
 
            if (start != ending)
            {
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }
 
            lazy[node] = 0;
        }
    }
 
    int query(int start, int ending, int l, int r, int node)
    {
        push(start, ending, node);
 
        if (start > r || ending < l)
        {
            return LLONG_MIN;
        }
 
        if (start >= l && ending <= r)
        {
            return st[node];
        }
 
        int mid = (start + ending) / 2;
 
        int q1 = query(start, mid, l, r, 2 * node + 1);
        int q2 = query(mid + 1, ending, l, r, 2 * node + 2);
 
        return max(q1, q2);
    }
 
    void update(int start, int ending, int node, int l, int r, int value)
    {
        push(start, ending, node);
 
        if (start > r || ending < l)
        {
            return;
        }
 
        if (start >= l && ending <= r)
        {
            lazy[node] += value;
            push(start, ending, node);            
            return;
        }
 
        int mid = (start + ending) / 2;
 
        update(start, mid, 2 * node + 1, l, r, value);
 
        update(mid + 1, ending, 2 * node + 2, l, r, value);
 
        st[node] = max(st[node * 2 + 1], st[node * 2 + 2]);
 
        return;
    }
 
    int query(int l, int r)
    {
        return query(0, n - 1, l, r, 0);
    }
 
    void update(int l, int r, int x)
    {
        update(0, n - 1, 0, l, r, x);
    }
};


 struct SegTree {
    int n;
    struct Node { int mx, add; };
    vector<Node> st;
    SegTree(int _n): n(_n), st(4*n+4,{0,0}) {}
    void apply(int p, int v) {
        st[p].mx += v;
        st[p].add += v;
    }
    void push(int p) {
        if (st[p].add) {
            apply(p<<1, st[p].add);
            apply(p<<1|1, st[p].add);
            st[p].add = 0;
        }
    }
    void pull(int p) {
        st[p].mx = max(st[p<<1].mx, st[p<<1|1].mx);
    }
    void update(int p, int l, int r, int i, int j, int v) {
        if (i > r || j < l) return;
        if (i <= l && r <= j) {
            apply(p, v);
            return;
        }
        push(p);
        int m = (l + r) >> 1;
        update(p<<1, l, m, i, j, v);
        update(p<<1|1, m+1, r, i, j, v);
        pull(p);
    }
    // add v on [i..j]
    void update(int i, int j, int v) {
        if (i <= j)
            update(1, 1, n, i, j, v);
    }
    int queryMax() { return st[1].mx; }
};