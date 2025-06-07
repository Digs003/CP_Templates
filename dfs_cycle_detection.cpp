int dfs1(int u){//edge from u->r[u]
    if(color[r[u]]==2){
        color[u]=2;
        return -1;
    }
    if(color[r[u]]==1){
        color[u]=2;
        cycle[u]=true;
        return r[u];
    }
    color[u]=1;
    int res=dfs1(r[u]);
    if(res==-1){
        color[u]=2;
        return -1;
    }
    if(res==u){
        color[u]=2;
        cycle[u]=true;
        return -1;
    }
    color[u]=2;
    cycle[u]=true;
    return res;
} 



// int dfs(int u,int p,vi& cyc){
//     vis[u]=1;
//     cyc.pb(u);
//     for(auto v:adj[u]){
//         if(vis[v]==0){
//             if(dfs(v,u,cyc))return 1;
//         }else if(vis[v]==1 && v!=p){
//             cyc.pb(v);
//             return 1;
//         }
//     }
//     vis[u]=2;
//     cyc.pop_back();
//     return 0;
// }


// void solve(){
//     int n,m;
//     cin>>n>>m;
//     adj=vvi(n+1);
//     vis=vi(n+1);
//     fr(i,0,m){
//         int a,b;
//         cin>>a>>b;
//         adj[a].pb(b);
//         adj[b].pb(a);
//     }
//     vi cyc;
//     bool f=0;
//     fr(i,1,n+1){
//         if(!vis[i]){
//             if(dfs(i,-1,cyc)){
//                 int x=cyc.size();
//                 vi res;
//                 res.pb(cyc[x-1]);
//                 for(int i=x-2;i>=0;i--){
//                     res.pb(cyc[i]);
//                     if(cyc[i]==cyc[x-1])break;
//                 }
//                 reverse(all(res));
//                 cout<<res.size()<<endl;
//                 out(res,(int)res.size());
//                 f=1;
//                 break;
//             }
//         }
//     }
//     if(!f){
//         cout<<"IMPOSSIBLE"<<endl;
//     }
// }