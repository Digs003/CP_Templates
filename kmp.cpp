
//Count of occurence of each prefix in a string
#include<bits/stdc++.h>

#define pb push_back
#define elif else if
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define vi vector<int>
#define vl vector<long long>
#define vvl vector<vector<long long>>
#define vvi vector<vector<int>>
#define pll pair<long long,long long> 
#define pii pair<int,int>
#define fr(i,a,b) for(ll i=a;i<b;i++)
#define rev(i,a,b) for(ll i=a;i>=b;i--)
#define in(a,n) fr(i,0,n) cin>>a[i] 
#define in1(a,n) fr(i,1,n+1) cin>>a[i]
#define out(a,n) fr(i,0,n) cout<<a[i]<<' '; cout<<"\n"
#define all(o) (o).begin(), (o).end()
#define maxHeap(a) priority_queue<a>
#define minHeap(a) priority_queue<a,vector<a>,greater<a>>
#define yess cout<<"YES"<<endl
#define noo cout<<"NO"<<endl
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

using namespace std;
ll gcd(ll a, ll b){ return b == 0 ? a : gcd(b, a % b); }    




int n;
string s;
vi lps;
void kmp(){
	int i=0,j=-1;
	lps[0]=-1;
	while(i<n){
		while(j!=-1 && s[j]!=s[i])j=lps[j];
		i++;
		j++;
		lps[i]=j;
	}

}




int main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int t=1;
    //cin>>t;
    while(t--){
        cin>>n;
        cin>>s;
        lps=vi(n+1);
        kmp();
        vi occ(n+1,0);
        fr(i,1,n+1){
        	occ[lps[i]]++;
        }
        for(int i=n-1;i>=1;i--){
        	occ[lps[i]]+=occ[i];
        }
        fr(i,1,n+1)occ[i]++;

        fr(i,1,n+1){
        	cout<<s.substr(0,i)<<" ";
        	cout<<occ[i]<<endl;
        }
        cout<<endl;



    }
    return 0;
}