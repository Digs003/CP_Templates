#include<bits/stdc++.h>

#define pb push_back
#define elif else if
#define endl '\n'
#define ll long long
#define ld long double
#define ff first
#define ss second
#define vi vector<int>
#define vl vector<long long>
#define vb vector<bool>
#define vvl vector<vector<long long>>
#define vvi vector<vector<int>>
#define pii pair<int,int>
#define fr(i,a,b) for(ll i=a;i<b;i++)
#define in(a,n) fr(i,0,n) cin>>a[i] 
#define in1(a,n) fr(i,1,n+1) cin>>a[i]
#define out(a,n) fr(i,0,n) cout<<a[i]<<' '; cout<<"\n"
#define all(o) (o).begin(), (o).end()
#define maxHeap(a) priority_queue<a>
#define minHeap(a) priority_queue<a,vector<a>,greater<a>>
#define yess cout<<"YES"<<endl
#define noo cout<<"NO"<<endl
#define print(f) cout << (f ? "YES" : "NO") << '\n'
#define chmax(a,x) a=max(a,x)
#define chmin(a,x) a=min(a,x)
#ifndef ONLINE_JUDGE
#define dbg(x) cout<<#x<<" "<<x<<endl;
#else
#define dbg(x)
#endif
#ifndef ONLINE_JUDGE
#define debarr(a,n) cout<<#a<<" : ";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl;
#else
#define debarr(x,n)
#endif
#define int long long
using namespace std;
int gcd(int a, int b){ return b == 0 ? a : gcd(b, a % b); }
const int mod=1e9+7;    

int dp[20][2][2][20];
string L,R;

int rec(int depth,int lo,int hi,int nonzero_idx){
    //Fixed Template starts
    if(depth==(int)R.length()){
        return 1;
    }
    if(dp[depth][lo][hi][nonzero_idx]!=-1)return dp[depth][lo][hi][nonzero_idx];

    int ans=0;
    int lolim=0,hilim=9;
    if(hi==1){
        hilim=R[depth]-'0';
    }
    if(lo==1){
        lolim=L[depth]-'0';
    }
    //Fixed Template ends
    if(depth<nonzero_idx){
        hilim=0;
    }
    for(int i=lolim;i<=hilim;i++){
        if(depth>=nonzero_idx){
            if(i%2!=(depth-nonzero_idx+1)%2){
                continue;
            }
        }
        int nhi=hi;
        int nlo=lo;
        if(i!=R[depth]-'0'){
            nhi=0;
        }
        if(i!=L[depth]-'0'){
            nlo=0;
        }
        ans=ans+rec(depth+1,nlo,nhi,nonzero_idx);
    }
    return dp[depth][lo][hi][nonzero_idx]=ans;
}



void solve(){
    
    cin>>L>>R;
    int extra=R.length()-L.length();
    string tmp="";
    while(extra--)tmp+="0";
    L=tmp+L;
    memset(dp,-1,sizeof(dp));

    
    int res=0;
    for(int i=0;i<(int)R.length();i++){
        res=res+rec(0,1,1,i);
    }
    cout<<res<<endl;
}
signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int TC=1;
    cin>>TC;
    while(TC--){
        solve();
    }
    return 0;
}