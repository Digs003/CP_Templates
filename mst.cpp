//Kruskal O(ElogE)
struct UnionFind {
	int n,set_sz, *par, *rank;
	UnionFind(){}
	UnionFind(int a){
		n=set_sz=a;
		par=new int[n+1];
		rank=new int[n+1];
		for(int i=1;i<=n;i++){
			par[i]=i;
			rank[i]=i;
		}
	}
	int find(int x){
		if(x!=par[x]) return par[x]=find(par[x]);
		return x;
	}
	void merge(int x,int y){
		int xroot=find(x),yroot=find(y);
		if(xroot!=yroot){
			if(rank[xroot]>=rank[yroot]){
				par[yroot]=xroot;
				rank[xroot]+=rank[yroot];
			}
			else{
				par[xroot]=yroot;
				rank[yroot]+=rank[xroot];
			}
			set_sz--;
		}
	}
	void reset(){
		set_sz=n;
		for(int i=1;i<=n;i++){
			par[i]=i;
			rank[i]=i;
		}
	}
	int size(){
		return set_sz;
	}
	void print(){
		for(int i=1;i<=n;i++){
			cout<<i<<"->"<<par[i]<<endl;
		}
	}
};


struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};


void solve(){
	int n,m;
	vector<Edge> edges;
	int cost=0;
	vector<Edge>result;
	cin>>n>>m;
	fr(i,0,m){
		int a,b,c;
		cin>>a>>b>>c;
		edges.pb(Edge(a,b,c));
	}
	UnionFind uf(n);
	sort(all(edges));
	for(Edge e:edges){
		if(uf.find(e.u)!=uf.find(e.v)){
			cost+=e.weight;
			result.pb(e);
			uf.merge(e.u,e.v);
		}
	}
}