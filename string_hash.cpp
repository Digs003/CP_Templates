ll quickhash(string s,ll p,ll mod){
	ll ans=(s[0]-'a'+1);
	for(int i=1;i<s.length();i++){
		ans=(ans*p+(s[i]-'a'+1))%mod;
	}
	return ans;
}

struct hasher{
	int sz;
	ll mod,p;
	vector<ll>fHash,rHash;
	vector<ll>pk;
	void init(string s,ll _p,ll _mod){
		mod=_mod;
		p=_p;
		sz=s.length();
		fHash.resize(sz);
		rHash.resize(sz);
		pk.resize(sz);
		fHash[0]=s[0]-'a'+1;
		pk[0]=1;
		for(int i=1;i<s.length();i++){
			fHash[i]=(fHash[i-1]*p+(s[i]-'a'+1))%mod;
			pk[i]=(pk[i-1]*p)%mod;
		}
		rHash[sz-1]=(s[sz-1]-'a'+1);
		for(int i=sz-2;i>=0;i--){
			rHash[i]=(rHash[i+1]*p+(s[i]-'a'+1))%mod;
		}

	}
	ll getfHash(int l,int r){
		if(l==0){
			return fHash[r];
		}
		else{
			return ((fHash[r]-fHash[l-1]*pk[r-l+1])%mod+mod)%mod;
		}
	}
	ll getrHash(int l,int r){
		if(r==sz-1){
			return rHash[l];
		}
		return ((rHash[l]-rHash[r+1]*pk[r-l+1])%mod+mod)%mod;
	}
};


struct double_hash{
	hasher a,b;
	void init(string s){
		a.init(s,37,1e9+9);
		b.init(s,39,1e9+21);
	}
	pair<ll,ll> getfHash(int l,int r){
		return {a.getfHash(l,r),b.getfHash(l,r)};
	}
	pair<ll,ll> getrHash(int l,int r){
		return {a.getrHash(l,r),b.getrHash(l,r)};
	}
	bool is_palin(int l,int r){
		return getfHash(l,r)==getrHash(l,r);
	}
};