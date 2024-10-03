int n;
vector<vector<int>>adj;
vector<int>dis;
vector<int>par;

void dfs(int u,int p,int d){
	dis[u]=d;
	par[u]=p;
	for(auto v:adj[u]){
		if(v!=p){
			dfs(v,u,d+1);
		}
	}
}

void solve(){
	cin>>n;
	adj.resize(n+1);
	dis.resize(n+1);
	par.resize(n+1);
	fr(i,0,n-1){
		int u,v;
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(1,0,0);
	int max1=1;
	fr(i,2,n+1){
		if(dis[maxi]<dis[i])max1=i;
	}
	dfs(max1,0,0);
	int max2=1;
	fr(i,2,n+1){
		if(dis[max2]<dis[i])max2=i;
	}
	cout<<dis[max2]<<endl;//Diameter
	vector<int>path;
	int temp=max2;
	while(temp!=0){
		path.pb(temp);
		temp=par[temp];
	}

	//Center
	if(path.size()%2){
		cout<<path[path.size()/2];
	}
	else{
		cout<<path[path.size()/2]<<" ";
		cout<<path[(path.size()-1)/2]<<" ";
	}
}