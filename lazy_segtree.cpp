const ll N=2*1e5+5;
ll arr[N];

struct node{
  ll sum,lazy;
  bool isLazy;
  node(){
    sum=0;
    lazy=0;
    isLazy=false;
  }
};

node merge(const node& a,const node& b){
  node temp;
  temp.sum=a.sum+b.sum;
  return temp;
}

node tree[4*N];

void build(ll idx,ll l,ll r){
  if(l==r){
    tree[idx].sum=arr[l];
    return;
  }
  ll mid=(l+r)>>1;
  build(2*idx,l,mid);
  build(2*idx+1,mid+1,r);
  tree[idx]=merge(tree[2*idx],tree[2*idx+1]);
}

void push(ll idx,ll l,ll r){
  if(tree[idx].isLazy){
    tree[idx].sum+=tree[idx].lazy*(r-l+1);
    if(l!=r){
      tree[idx*2].lazy+=tree[idx].lazy;
      tree[idx*2].isLazy=true;
      tree[idx*2+1].lazy+=tree[idx].lazy;  
      tree[idx*2+1].isLazy=true;
    }
    tree[idx].lazy=0;
    tree[idx].isLazy=false;
  }
}

void update(ll idx,ll l,ll r,ll lq,ll rq,ll v){
  push(idx,l,r);
  if(lq>r || l>rq)return;
  if(lq<=l && r<=rq){
    tree[idx].isLazy=true;
    tree[idx].lazy+=v;
    push(idx,l,r);
    return;
  }
  ll mid=(l+r)>>1;
  update(2*idx,l,mid,lq,rq,v);
  update(2*idx+1,mid+1,r,lq,rq,v);
}

node query(ll idx,ll l,ll r,ll lq,ll rq){
  push(idx,l,r);
  if(lq>r || l>rq)return node();
  if(lq<=l && r<=rq){
    return tree[idx];
  }
  ll mid=(l+r)>>1;
  return merge(query(2*idx,l,mid,lq,rq),query(2*idx+1,mid+1,r,lq,rq));
}