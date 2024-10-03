//Minimum in a window of k elements
struct monotone_deque{
	deque<int>dq;
	void insert(int x){
		while(!dq.empty() && dq.back()>x)dq.pop_back();
		dq.push_back(x);
	}
	int getmin(){
		return dq.front();
	}
	void erase(int x){
		if(dq.front()==x){
			dq.pop_front();
		}
	}
};

vector<int> previousSmaller(vector<int>& arr){
	int n=arr.size();
	vector<int>pse(n,-1);
	stack<int.st;
	for(int i=0;i<n;i++){
		while(!st.empty() && st.top()>=arr[i]){
			st.pop();
		}
		if(!st.empty()){
			pse[i]=st.top();
		}
		st.push(arr[i]);
	}
	return pse;
}

vector<int> nextSmaller(vector<int>& arr){
	int n=arr.size();
	vector<int>nse(n,-1);
	stack<int.st;
	for(int i=n-1;i>=0;i--){
		while(!st.empty() && st.top()>=arr[i]){
			st.pop();
		}
		if(!st.empty()){
			nse[i]=st.top();
		}
		st.push(arr[i]);
	}
	return nse;
}
