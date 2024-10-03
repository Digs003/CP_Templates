
//Binary Exponentiation //O(log N)
long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

//Extended Euclidean Algorithm
int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}


//Modular inverse
int inv(int a) {
  return a <= 1 ? a : m - (long long)(m/a) * inv(m % a) % m;
}
//O(logn)
ll sqrt_(ll n){
    ll l=0,r=3000000000;
    while(r-l>1){
        ll mid=l+(r-l)/2;
        if(1ll*mid*mid<=n)l=mid;
        else{
            r=mid;
        }
    }
   