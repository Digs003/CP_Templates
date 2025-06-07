//Mail Delivery (Undirected)
//Teleporters Path(Directed)

#include<bits/stdc++.h>
 
#define pb push_back
#define elif else if
#define endl '\n'
#define ll long long
#define ld long double
#define ff first
#define ss second
#define vi vector<int>
#define vl vector<long long>
#define vb vector<bool>
#define vvl vector<vector<long long>>
#define vvi vector<vector<int>>
#define pii pair<int,int>
#define fr(i,a,b) for(ll i=a;i<b;i++)
#define in(a,n) fr(i,0,n) cin>>a[i] 
#define in1(a,n) fr(i,1,n+1) cin>>a[i]
#define out(a,n) fr(i,0,n) cout<<a[i]<<' '; cout<<"\n"
#define all(o) (o).begin(), (o).end()
#define maxHeap(a) priority_queue<a>
#define minHeap(a) priority_queue<a,vector<a>,greater<a>>
#define yess cout<<"YES"<<endl
#define noo cout<<"NO"<<endl
#define print(f) cout << (f ? "YES" : "NO") << '\n'
#define chmax(a,x) a=max(a,x)
#define chmin(a,x) a=min(a,x)
#ifndef ONLINE_JUDGE
#define dbg(x) cout<<#x<<" "<<x<<endl;
#else
#define dbg(x)
#endif
#ifndef ONLINE_JUDGE
#define debarr(a,n) cout<<#a<<" : ";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl;
#else
#define debarr(x,n)
#endif
#define int long long
using namespace std;
int gcd(int a, int b){ return b == 0 ? a : gcd(b, a % b); }
const int mod=1e9+7;    
vector<vector<pii>> adj;
vi vis_edges;
vi path;
 
//O(E)
void dfs(int u){
    while(!adj[u].empty()){
        auto [v,e]=adj[u].back();
        adj[u].pop_back();
        if(vis_edges[e])continue;
        vis_edges[e]=true;
        dfs(v);
    }
    path.pb(u);
}
 
 
void solve(){
    int n,m;
    cin>>n>>m;
    adj.resize(n);
    vis_edges.resize(m);
    vi deg(n);
    fr(i,0,m){
        int a,b;
        cin>>a>>b;
        a--;b--;
        adj[a].pb({b,i});
        adj[b].pb({a,i});
        deg[a]++;
        deg[b]++;
    }
    fr(i,0,n){
        if(deg[i]%2){
            cout<<"IMPOSSIBLE"<<endl;
            return;
        }
    }
    path.clear();
    dfs(0);
    // debarr(path,path.size());
    if((int)path.size()!=m+1){
        cout<<"IMPOSSIBLE"<<endl;
    }else{
        for(auto x:path){
            cout<<x+1<<" ";
        }
        cout<<endl;
    }
 
 
    
}
signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int TC=1;
    //cin>>TC;
    while(TC--){
        solve();
    }
    return 0;
}