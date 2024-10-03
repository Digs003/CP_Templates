
//O(ElogE)
int n,m;
vector<pair<int,int>> adj[N];
ll dist[N];
int vis[N];

class prioritize{
public:
	bool operator()(pair<int,int>&p1,pair<int,int>&p2){
		return p1.ss > p2.ss;
	}
};

void dijkstra(int sc){
	fr(i,0,n){
		dist[i]=1e18;
		vis[i]=0;
	}
	dist[sc]=0;
	priority_queue<pair<int,int>,vector<pair<int,int>>,prioritize> pq;
	pq.push(mp(sc,0));
	while(!pq.empty()){
		pair<int,int> curr=pq.top();
		pq.pop();
		if(vis[curr.ff])continue;
		vis[curr.ff]=1;
		for(auto v:adj[curr.ff]){
			int neigh=v.ff;
			int wt=v.ss;
			if(dist[neigh]>dist[curr.ff]+wt){
				dist[neigh]=dist[curr.ff]+wt;
				pq.push(mp(neigh,dist[neigh]));
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
		adj[a].pb({b,c});//Cosnidering undirected graph
		adj[b].pb({a,c});
	}
	dijkstra(1);
}


