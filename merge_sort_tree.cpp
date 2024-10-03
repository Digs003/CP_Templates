int arr[N];
vi tree[4*N];

//O(NlogN)
void build(int idx,int l,int r){
	if(l==r){
		tree[idx].pb(arr[l]);
		return;
	}
	int mid=(l+r)>>1;
	build(idx*2,l,mid);
	build(idx*2+1,mid+1,r);
	tree[idx]=merge(tree[2*idx],tree[2*idx+1]);
}

//Finding number of elements <=k in [lq,rq]
//O(log^2n)
int query(int idx,int l,int r,int lq,int rq,k){
	if(r<lq || l>rq){
		return 0;
	}
	if(lq<=l && r<=rq){
		return upper_bound(all(tree[idx]),k)-tree[idx].begin();//Note:upper bound gives elements <=x  AND Lower bound gives element < x
	}
	int mid=(l+r)>>1;
	return query(2*idx,l,mid,lq,rq,k)+query(2*idx+1,mid+1,r,lq,rq,k);
}


vi merge(vi& arr1, vi& arr2){
	vi mergedArray;
	int i = 0, j = 0;
    int n1 = arr1.size(), n2 = arr2.size();

    while (i < n1 && j < n2) {
        if (arr1[i] <= arr2[j]) {
            mergedArray.pb(arr1[i]);
            i++;
        } else {
            mergedArray.pb(arr2[j]);
            j++;
        }
    }

    while (i < n1) {
        mergedArray.pb(arr1[i]);
        i++;
    }

    while (j < n2) {
        mergedArray.pb(arr2[j]);
        j++;
    }
    return mergedArray;
}