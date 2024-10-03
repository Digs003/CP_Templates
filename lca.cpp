//O(NlogN)[For a tree]
void dfs(int node,int par,int dep){
	f[0][node]=par;
	depth[node]=dep;
	fr(i,1,20){
		f[i][node]=f[i-1][f[i-1][node]];
	}
	for(auto v:adj[node]){
		if(v!=par){
			dfs(v,node,dep+1);
		}
	}
}


//O(logN)
int lca(int u,int v){
	if(depth[u]<depth[v]){
		swap(u,v);
	}
	for(int i=19;i>=0;i--){
		if((depth[u]-depth[v]) &(1LL<<i)){
			u=f[i][u];
		}
	}
	if(u==v)return u;
	for(int i=19;i>=0;i--){
		if(f[i][v]!=f[i][u]){
			v=f[i][v];
			u=f[i][u];
		}
	}
	return f[0][u];
}