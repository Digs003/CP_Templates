//Two Pointer

// int head=-1;
// int tail=0;

while(tail<n){
	while(head+1<n && [cond.]){
		head++;
	}
	ans=max(ans,curr);
	if(head>=tail){
		tail++;
	}else{
		tail++;
		head=tail-1;
	}
}


//Count distinct element in a range in O(1):-
int cntdistinct=0;
int freq[10000001];

void insert(int x){
	freq[x]++;
	if(freq[x]==1){
		cntdistinct++;
	}

}

void remove(int x){
	freq[x--];
	if(freq[x]==0){
		cntdistinct--;
	}
}




//QUESTION
//Given n,k,d  and array arr find the subarray with maximum sum possible so that no. of odd numbers in subarray <=k and subarray sum<=d
//Time-O(nlogn) Using multiset and prefix sum along with two pointer


ll pref[n];
fr(i,0,n){
	pref[i]=arr[i];
	if(i){
		pref[i]+=pref[i-1];
	}
}

int head=-1;
int tail=0;
multiset<ll>mt;
int oddCnt=0;
ll best=-1e18;
while(tail<n){
	while(head+1<n && ((oddcnt<k && arr[head+1]%2) || (oddcnt<=k && arr[head+1]%2==0))){
		head++;
		if(arr[head]%2)oddCnt++;
		mt.insert(pref[head]);
	}
	ll temp=d+(tail>0?pref[tail-1]:0);
	auto it=mt.upper_bound(temp);
	if(it!=mt.begin()){
		it--;
		best=max(best,*it-(tail>0?pref[tail-1]:0));
	}
	if(head<tail){
		tail++;
		head=tail-1;
	}else{
		mt.erase(mt.find(pref[tail]));
		if(arr[tail]%2)oddCnt--;
		tail++;
	}
}
