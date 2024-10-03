int n;
vector<vector<int>> adj;
vector<int> subtreeSZ;
vector<int>centroid;

void dfs(int u,int p){
	subtreeSZ[u]=1;
	for(auto v:adj[u]){
		if(v!=p){
			dfs(v,u);
			subtreeSZ[u]+=subtreeSZ[v];
		}
	}
	bool isCentroid=true;
	for(auto v:adj[u]){
		if(v!=p){
			if(subtreeSZ[v]>n/2)isCentroid=false;
		}
	}
	if(n-subtreeSZ[u]>n/2)isCentroid=false;
	if(isCentroid){
		centroid.pb(u);
	}
}

void solve(){
	cin>>n;
	adj.resize(n+1);
	subtreeSZ.resize(n+1);
	fr(i,0,n-1){
		int u,v;
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

}	