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
#define pii pair<int,int>
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
#define debarr(x,n)
#endif

using namespace std;
ll gcd(ll a, ll b){ return b == 0 ? a : gcd(b, a % b); }    

vvi adj;
vvi adjR;
vi vis;
vi order;

void dfs1(int u){
    vis[u]=1;
    for(auto v:adj[u]){
        if(!vis[v]){
            dfs1(v);
        }
    }
    order.pb(u);
}

void dfs2(int u){
    vis[u]=1;
    for(auto v:adjR[u]){
        if(!vis[v]){
            dfs2(v);
        }
    }
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
        order.clear();
        int n,m;
        cin>>n>>m;
        adj=vvi(n+1);
        adjR=vvi(n+1);
        vis=vi(n+1,0);
        fr(i,0,m){
            int a,b;
            cin>>a>>b;
            adj[a].pb(b);
            adjR[b].pb(a);
        }
        fr(i,1,n+1){
            if(!vis[i]){
                dfs1(i);
            }
        }
        reverse(all(order));
        vis=vi(n+1,0);
        int cnt=0;
        vi nodes;
        for(auto u:order){
            if(!vis[u]){
                nodes.pb(u);
                cnt++;
                dfs2(u);
            }
        }
        if(cnt==1){
            yess;
        }else{
            noo;
            cout<<nodes[1]<<" "<<nodes[0]<<endl;

        }



    }
    return 0;
}