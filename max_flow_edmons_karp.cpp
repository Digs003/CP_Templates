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

int main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int t=1;
    //cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vvi adj(n);
        vvl capacity(n,vl(n,0));
        fr(i,0,m){
            int a,b,c;
            cin>>a>>b>>c;
            a--,b--;
            adj[a].pb(b);
            adj[b].pb(a);
            capacity[a][b]+=c;
        }
        vi par(n,-1);
        auto bfs=[&]()->bool{
            queue<int>q;
            q.push(0);
            while(!q.empty()){
                int curr=q.front();
                q.pop();
                for(auto v:adj[curr]){
                    ll w=capacity[curr][v];
                    if(w<=0 || par[v]!=-1)continue;
                    par[v]=curr;
                    q.push(v);
                }
            }
            return par[n-1]!=-1;
        };
        ll flow=0;
        while(bfs()){
            int u=n-1;
            ll curr_flow=1e18;
            while(u!=0){
                curr_flow=min(curr_flow,capacity[par[u]][u]);
                u=par[u];
            }
            u=n-1;
            while(u!=0){
                capacity[par[u]][u]-=curr_flow;
                capacity[u][par[u]]+=curr_flow;
                u=par[u];
            }
            flow+=curr_flow;
            fill(all(par),-1);
        }
        cout<<flow<<endl;


    }
    return 0;
}