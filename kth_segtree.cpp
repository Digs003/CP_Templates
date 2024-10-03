//Problem Link: https://placewit.medium.com/order-of-people-heights-2a7c93dbc618

#include<bits/stdc++.h>

#define pb push_back
#define elif else if
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define vi vector<int>
#define vl vector<long long>
#define vvl vector<vector<long long>>
#define vvi vector<vector<int>>
#define pll pair<long long,long long> 
#define fr(i,a,b) for(ll i=a;i<b;i++)
#define rev(i,a,b) for(ll i=a;i>=b;i--)
#define in(a,n) fr(i,0,n) cin>>a[i] 
#define in1(a,n) fr(i,1,n+1) cin>>a[i]
#define out(a,n) fr(i,0,n) cout<<a[i]<<' '; cout<<"\n"
#define all(o) (o).begin(), (o).end()
#define maxHeap(a) priority_queue<a>
#define minHeap(a) priority_queue<a,vector<a>,greater<a>>
#define yess cout<<"YES"<<endl
#define noo cout<<"NO"<<endl
#ifndef ONLINE_JUDGE
#define dbg(x) cout<<#x<<" "<<x<<endl;
#else
#define dbg(x)
#endif
#ifndef ONLINE_JUDGE
#define debarr(a,n) cout<<#a<<" : ";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl;
#else
#define debarr(x)
#endif

using namespace std;
const int N=1e5+5;
int tree[4*N];
void build(int idx,int l,int r){
  if(l==r){
    tree[idx]=1;
    return;
  }
  int mid=(l+r)>>1;
  build(idx*2,l,mid);
  build(idx*2+1,mid+1,r);
  tree[idx]=tree[2*idx]+tree[2*idx+1];
}

int findKthEmpty(int idx,int l,int r,int k){
  tree[idx]--;
  if(l==r){
    return l;
  }
  int mid=(l+r)>>1;
  if(tree[2*idx]>=k){
    return findKthEmpty(2*idx,l,mid,k);
  }
  return findKthEmpty(2*idx+1,mid+1,r,k-tree[2*idx]);
}


int main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int t=1;
    //cin>>t;
    while(t--){
      int n;
      cin>>n;
      vi h(n),infront(n);
      in(h,n);
      in(infront,n);
      vvi inc_height(n,vi(2));
      fr(i,0,n){
        inc_height[i][0]=h[i];
        inc_height[i][1]=infront[i];
      }
      sort(all(inc_height));
      fr(i,0,n){
        h[i]=inc_height[i][0];
        infront[i]=inc_height[i][1];
      }
      build(1,0,n-1);
      vi ans(n);
      fr(i,0,n){
        int slot=findKthEmpty(1,0,n-1,infront[i]+1);
        dbg(slot);
        ans[slot]=h[i];
      }
      out(ans,n);
    }
    return 0;
}