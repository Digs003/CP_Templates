//DFS Approach
vector<int> adj[N];
int vis[N];
vector<int>topo;
void dfs(int node){
	vis[node]=1;
	for(auto v:adj[node]){
		if(!vis[v]){
			dfs(v);
		}
	}
	topo.pb(node);
}

void solve(){
	int n,m;
	cin>>n>>m;
	fr(i,0,m){
		int x,y;
		cin>>x>>y;
		x--;
		y--;
		adj[x].pb(y);
	}
	fr(i,0,n){
		if(!vis[i]){
			dfs(i);
		}
	}
	reverse(topo.begin(),topo.end());
}

//Kahn's Algo.(Used to detect cycles in graphs)
//For lexicographical ordering use priority_queue instrad of queue
int n,m;
vector<int> adj[N];
int indegree[N];
vector<int>topo;


void kahn(){
	queue<int>q;
	for(int i=0;i<n;i++){
		if(indegree[i]==0){
			q.push(i);
		}
	}
	while(!q.empty()){
		int x=q.front();
		q.pop();
		topo.pb(x);
		for(auto v:adj[x]){
			indegree[v]--;
			if(indegree[v]==0){
				q.push(v);
			}
		}
	}


}

void solve(){
	
	cin>>n>>m;
	fr(i,0,m){
		int x,y;
		cin>>x>>y;
		x--;
		y--;
		adj[x].pb(y);
		indegree[y]++;

	}
	kahn();
	
}
