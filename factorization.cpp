bool isPrime(int x) {
    for (int d = 2; d * d <= x; d++) {
        if (x % d == 0)
            return false;
    }
    return x >= 2;
}

vl divisors(ll x){
    vl ans;
    for(ll i=1;i*i<=x;i++){
        if(x%i==0){
            ans.pb(i);
            if(i*i!=x){
                ans.pb(x/i);
            }
        }
    }
    return ans;
}

long long numberOfDivisors(long long num) {
    long long total = 1;
    for (int i = 2; (long long)i * i <= num; i++) {
        if (num % i == 0) {
            int e = 0;
            do {
                e++;
                num /= i;
            } while (num % i == 0);
            total *= e + 1;
        }
    }
    if (num > 1) {
        total *= 2;
    }
    return total;
}


//O(n^1/2)
using ii=pair<ll,ll>
vector<ii> factors(ll x){
    vector<ii> ans;
    for(ll i=2;i*i<=x;i++){
        if(x%i==0){
            int cnt=0;
            while(x%i==0){
                cnt++;
                x/=i;
            }
            ans.pb({i,cnt});
        }
    }
    if(x>1){
        ans.pb({x,1});
    }
}