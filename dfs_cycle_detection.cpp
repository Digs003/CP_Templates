int dfs(int u){
	vis[u]=1;
	if(vis[a[u]]==1){
		cyc[u]=a[u];
		vis[u]=2;
		if(u==a[u])return -1;
		return a[u];
	}
	if(vis[a[u]]==2){
		cyc[u]=-1;
		vis[u]=2;
		return -1;
	}
	int x=dfs(a[u]);
	cyc[u]=x;
	vis[u]=2;
	if(x==u)return -1;
	return x;
}