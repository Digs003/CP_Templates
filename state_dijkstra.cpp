#include<bits/stdc++.h>

#define pb push_back
#define elif else if
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
vector<vector<pll>> adj;
vvl dis;
ll n,m;

//state_dijkstra
void dijkstra(){
    priority_queue<vl,vector<vl>,greater<vl>>pq;
    dis[1][0]=0;
    dis[1][1]=0;
    pq.push({0,1,1});
    while(!pq.empty()){
        auto curr=pq.top();
        pq.pop();
        ll u=curr[1];
        ll dist=curr[0];
        ll avail=curr[2];
        if(dis[u][avail]<dist){
            continue;
        }
        for(auto it:adj[u]){
            if(avail){
                if(dis[it.ff][1]>dist+it.ss){
                    dis[it.ff][1]=dist+it.ss;
                    pq.push({dis[it.ff][1],it.ff,1});
                }
                if(dis[it.ff][0]>(dist+(it.ss)/2)){
                    dis[it.ff][0]=(dist+(it.ss)/2);
                    pq.push({dis[it.ff][0],it.ff,0});
                }
            }
            else{
                if(dis[it.ff][0]>dist+it.ss){
                    dis[it.ff][0]=dist+it.ss;
                    pq.push({dis[it.ff][0],it.ff,0});
                }
            }
        }
    }
    cout<<min(dis[n][0],dis[n][1])<<endl;
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
        cin>>n>>m;
        adj=vector<vector<pll>>(n+1);
        dis=vvl(n+1,vl(2,1e18));
        fr(i,0,m){
            ll a,b,c;
            cin>>a>>b>>c;
            adj[a].pb({b,c});
        }
        dijkstra();
    }
    return 0;
}