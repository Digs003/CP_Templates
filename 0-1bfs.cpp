int n,m;
vector<pair<int,int>> adj[N];
int dist[N];

void bfs01(int sc){
	deque<int> dq;
	fr(i,0,N)dist[i]=1e9;
	dist[sc]=0;
	dq.push_back(sc);
	while(!dq.empty()){
		int xx=dq.front();
		dq.pop_front();

		for(auto v:adj[xx]){
			int neighb=v.ff;
			int weight=v.ss;
			if(dist[neighb]>dist[xx]+weight){
				dist[neighb]=dist[xx]+weight;
				if(weight==0){
					dq.push_front(neighb);
				}else{
					dq.push_back(neighb);
				}
			}
		}
		
	}

}

void solve(){
	cin>>n>>m;
	fr(i,0,m){
		int a,b,c;
		cin>>a>>b>>c;//c={0,1} i.e., weight
		a--;
		b--;
		adj[a].pb({b,c});
		adj[b].pb({a,c});
	}
	int sc;
	cin>>sc;
	bfs01(sc);
}