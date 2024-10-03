
//Question is written on diary
ll dp[501][501];

ll rec(int l,int r){
	if(l==r){
		return 0;
	}
	if(dp[l][r]!=-1){
		return dp[l][r];
	}
	ll res=0;
	ll tot=0;
	fr(i,l,r+1){
		tot+=a[i];
	}
	ll left=0;
	for(int mid=l,mid<r;mid++){
		left+=a[i];
		res=max(res,rec(l,mid)+rec(mid+1,r)+((left)%100)*((tot-left)%100));
	}
	return dp[l][r]=res;
}

void solve(){
	memset(dp,-1,sizeof dp);
	int n;
	cin>>n;
	vi a(n);
	in(a,n);
}


//2nd Question
bool done [51][51];
ll dp[51][51][51];

ll rec(int l,int r,int xx){
	if(l==r){
		if(a[l]==xx)return 0;
		else return 1e18;
	}
	if(done[l][r]){
		return dp[l][r][xx];
	}
	for(int i=0;i<50;i++){
		dp[l][r][i]=1e18;
	}
	for(int mid=l;mid<r;mid++){
		for(int fs=0;fs<50;fs++){
			for(int ls=0;ls<50;ls++){
				dp[l][r][(fs*x+ls*y+z)%50]=min(dp[l][r][(fs*x+ls*y+z)%50],rec(l,mid,fs)+rec(mid+1,r,ls)+fs*ls);
			}
		}
	}
	done[l][r]=1;
	return dp[l][r][xx];
}