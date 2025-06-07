pii par[N];
int rank_dsu[N];
void init(int n){
    for(int i=0;i<n;i++){
        par[i]={i,0};
        rank_dsu[i]=1;
    }
}
pii find(int x){
    if(par[x].ff==x){
        return par[x];
    }
    else{
        pii parent=find(par[x].ff);
        par[x].ff=parent.ff;
        par[x].ss+=parent.ss;
        return par[x];
    }
}

void merge(int x,int y,int z){
    pii x_root=find(x),y_root=find(y);
    if(x_root.ff!=y_root.ff){
        if(rank_dsu[x_root.ff]>rank_dsu[y_root.ff]){
            rank_dsu[x_root.ff]+=rank_dsu[y_root.ff];
            par[y_root.ff].ff=x_root.ff;
            par[y_root.ff].ss=par[x].ss-par[y].ss-z;
        }else{
            rank_dsu[y_root.ff]+=rank_dsu[x_root.ff];
            par[x_root.ff].ff=y_root.ff;
            par[x_root.ff].ss=par[y].ss-par[x].ss+z;
        }
    }
}