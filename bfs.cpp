//BFS on a grid
int n,m;
vector<string>arr;
vector<vector<int>>dist;
vector<vector<pair<int,int>>> par;

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

bool check(int x,int y){
	if(x>=0 && x<n && y>=0 && y<m && arr[x][y]!='#')return 1;
	else return 0;
}


void bfs(pair<int,int>st){
	queue<pair<int,int>>q;

	dist=vector<vector<int>>(n,vector<int>(m,1e9));
	par=vector<vector<pair<int,int>>>(n,vector<pair<int,int>>(m,{0,0}));

	dist[st.ff][st.ss]=0;
	q.push(st);
	par[st.ff][st.ss]={-1,-1};
	while(!q.empty()){
		auto pos=q.front();
		q.pop();
		fr(k,0,4){
			if(check(pos.ff+dx[k],pos.ss+dy[k]) && dist[pos.ff+dx[k]][pos.ss+dy[k]]>dist[pos.ff][pos.ss]+1){
				dist[pos.ff+dx[k]][pos.ss+dy[k]]=dist[pos.ff][pos.ss]+1;
				par[pos.ff+dx[k]][pos.ss+dy[k]]={pos.ff,pos.ss};
				q.push({pos.ff+dx[k],pos.ss+dy[k]});
			}
		}
	}
}

void printpath(pair<int,int> x){
	if(x==make_pair(-1,-1))return;
	printpath(par[x.ff][x.ss]);
	cout<<x.ff<<" "<<x.ss<<endl;
}

void solve(){
	cin>>n>>m;
	arr.resize(n);
	fr(i,0,n){
		cin>>arr[i];
	}
	pair<int,int>>st,ex;
	cin>>st.ff>st.ss;
	cin>>ex.ff>>ex.ss;
	bfs(st);
	cout<<dist[ex.ff][ex.ss]<<endl;

}