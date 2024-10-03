ll LIS(vl& arr){
	vl len;
	for(auto x:arr){
		if(len.empty() || x>len.back()){
			len.pb(x);
		}else{
			auto it=lower_bound(all(len),x);
			*it=x;
		}
	}
	return len.size();
}