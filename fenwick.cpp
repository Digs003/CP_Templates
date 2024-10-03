struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n + 1;
        bit.assign(n + 1, 0);
    }

    FenwickTree(vector<int> a)
        : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int idx) {
        int ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            ret += bit[idx];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (++idx; idx < n; idx += idx & -idx)
            bit[idx] += delta;
    }
    void range_add(int l, int r, int delta) {
        add(l, delta);
        add(r + 1, -delta);
    }
};

//Coordinate compression(Useful to assign a value from 1 to n to each number in array when array elements are too big or negative)
set<int>s(all(a));
int j=1;
map<int,int>rank_mp;
for(auto x:s){
    rank_mp[x]=j;
    j++;
}
//Now while querying or updating use rank_mp[a[i]] instead of a[i]