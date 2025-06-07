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
#define print(f) cout << (f ? "YES" : "NO") << '\n'
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

vvi adj;
vvi adjR;  
vi vis;
vi order;
vi nodes;

void dfs1(int u){
    vis[u]=1;
    for(auto v:adj[u]){
        if(!vis[v]){
            dfs1(v);
        }
    }
    order.pb(u);
}

void dfs2(int u,int c){
    nodes[u]=c;
    vis[u]=1;
    for(auto v:adjR[u]){
        if(!vis[v]){
            dfs2(v,c);
        }
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
        int n,m;
        cin>>n>>m;
        adj=vvi(2*m+5);
        adjR=vvi(2*m+5);
        vis=vi(2*m+5);
        order=vi(2*m+5);
        fr(i,0,n){
            char a,b;
            int u,v;
            cin>>a>>u>>b>>v;
            u=2*u;
            v=2*v;
            if(a=='-'){
                u^=1;
            }
            if(b=='-'){
                v^=1;
            }
            int neg_u,neg_v;
            neg_u=u^1;
            neg_v=v^1;
            adj[neg_u].pb(v);
            adj[neg_v].pb(u);
            adjR[v].pb(neg_u);
            adjR[u].pb(neg_v);
        }
        fr(i,2,2*m+2){
            if(!vis[i]){
                dfs1(i);
            }
        }
        reverse(all(order));
        //debarr(order,order.size());
        vis=vi(2*m+5,0);
        nodes=vi(2*m+5);
        int j=0;
        for(auto u:order){
            if(!vis[u]){
                dfs2(u,j);
                j++;
            }
        }
        //debarr(nodes,nodes.size());
        vi assign(m+1);
        bool f=1;
        for(int i=2;i<=2*m+1;i+=2){
            if(nodes[i]==nodes[i+1]){
                dbg(i);
                f=0;
                break;
            }
            assign[i/2]=nodes[i]>nodes[i+1];
        }
        if(!f){
            cout<<"IMPOSSIBLE"<<endl;
        }else{
            fr(i,1,m+1){
                if(assign[i]){
                    cout<<"+ ";
                }else{
                    cout<<"- ";
                }
            }
            cout<<endl;
        }

    }
    return 0;
}