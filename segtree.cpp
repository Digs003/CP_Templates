struct SegmentTree {
    vector<ll> arr;
    vector<ll> tree;
    ll n;
 
    SegmentTree(ll n) {
        this->n = n;
        arr.resize(n);
        tree.resize(4 * n);
    }
    SegmentTree(vl& x){
        this->n=x.size();
        arr=x;
        tree.resize(4*n);
        build();
    }
 
    void build(ll idx, ll l, ll r) {
        if (l == r) {
            tree[idx] = arr[l];
            return;
        }
        ll mid = (l + r) >> 1;
        build(idx * 2, l, mid);
        build(idx * 2 + 1, mid + 1, r);
        tree[idx] = min(tree[2 * idx],tree[2 * idx + 1]);
    }
 
    void update(ll idx, ll l, ll r, ll pos, ll val) {
        if (pos < l || pos > r) return;
        if (l == r) {
            tree[idx] = val;
            arr[l] = val;
            return;
        }
        ll mid = (l + r) / 2;
        update(idx * 2, l, mid, pos, val);
        update(idx * 2 + 1, mid + 1, r, pos, val);
        tree[idx] = min(tree[2 * idx],tree[2 * idx + 1]);
    }
 
    ll query(ll idx, ll l, ll r, ll lq, ll rq) {
        if (l > rq || r < lq) {
            return 1e18;
        }
        if (lq <= l && r <= rq) {
            return tree[idx];
        }
        ll mid = (l + r) / 2;
        return min(query(idx * 2, l, mid, lq, rq),query(idx * 2 + 1, mid + 1, r, lq, rq));
    }
 
    void build() {
        build(1, 0, n - 1);
    }
 
    void update(ll pos, ll val) {
        update(1, 0, n - 1, pos, val);
    }
 
    ll query(ll lq, ll rq) {
        return query(1, 0, n - 1, lq, rq);
    }
};