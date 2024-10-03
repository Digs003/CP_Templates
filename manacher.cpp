#include<bits/stdc++.h>
using namespace std;

struct manacher{
	vector<int>p;
	void run_manacher(string s){
		cout<<s<<endl;
		int n=s.size();
		p.assign(n,1);
		int l=1,r=1;
		for(int i=1;i<n;i++){
			if(l+r-i<n && l+r-i>=0)p[i]=max(0,min(r-i,p[l+r-i]));
			while(i+p[i]<n && i-p[i]>=0 && s[i+p[i]]==s[i-p[i]]){
				p[i]++;
			}
			if(i+p[i]>r){
				l=i-p[i];
				r=i+p[i];
			}
		}
		for(auto v:p){
			cout<<v<<" ";
		}
		cout<<endl;
	}
	void build(string s){
		string t;
		for(auto v:s){
			t+=string("#")+v;
		}
		run_manacher(t+"#");
	}

	int getLongest(int cen,bool odd){
		int pos=2*cen+1+(!odd);
		return p[pos]-1;
	}
	bool checkPalin(int l,int r){
		if((r-l+1)<=getLongest((l+r)/2,l%2==r%2)){
			return 1;
		}
		return 0;
	}
};

