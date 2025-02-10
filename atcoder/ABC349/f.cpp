#include<bits/stdc++.h>
//#define int long long
using namespace std;
#define dbg(x...) \
do { \
	cout << #x << " -> "; \
	err(x); \
} while (0)

void err() {
	cout<<endl<<endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
	cout<<fixed<<setprecision(10)<<arg<< ' ';
	err(args...);
}
template<const int T>
struct ModInt {
	const static int mod = T;
	int x;
	ModInt(int x = 0) : x(x % mod) {}
	ModInt(long long x) : x(int(x % mod)) {} 
	int val() { return x; }
	ModInt operator + (const ModInt &a) const { int x0 = x + a.x; return ModInt(x0 < mod ? x0 : x0 - mod); }
	ModInt operator - (const ModInt &a) const { int x0 = x - a.x; return ModInt(x0 < 0 ? x0 + mod : x0); }
	ModInt operator * (const ModInt &a) const { return ModInt(1LL * x * a.x % mod); }
	ModInt operator / (const ModInt &a) const { return *this * a.inv(); }
	bool operator == (const ModInt &a) const { return x == a.x; };
	bool operator != (const ModInt &a) const { return x != a.x; };
	void operator += (const ModInt &a) { x += a.x; if (x >= mod) x -= mod; }
	void operator -= (const ModInt &a) { x -= a.x; if (x < 0) x += mod; }
	void operator *= (const ModInt &a) { x = 1LL * x * a.x % mod; }			
	void operator /= (const ModInt &a) { *this = *this / a; }
	friend ModInt operator + (int y, const ModInt &a){ int x0 = y + a.x; return ModInt(x0 < 			mod ? x0 : x0 - mod); }
	friend ModInt operator - (int y, const ModInt &a){ int x0 = y - a.x; return ModInt(x0 < 0 ? x0 + mod : x0); }			
	friend ModInt operator * (int y, const ModInt &a){ return ModInt(1LL * y * a.x % mod);}
	friend ModInt operator / (int y, const ModInt &a){ return ModInt(y) / a;}
	friend ostream &operator<<(ostream &os, const ModInt &a) { return os << a.x;}
	friend istream &operator>>(istream &is, ModInt &t){return is >> t.x;}						
				
	ModInt pow(long long n) const {
	ModInt res(1), mul(x);
		while(n){
			if (n & 1) res *= mul;
			mul *= mul;
			n >>= 1;
		}
		return res;
	}
				
	ModInt inv() const {
		int a = x, b = mod, u = 1, v = 0;
		while (b) {
			int t = a / b;
			a -= t * b; swap(a, b);
			u -= t * v; swap(u, v);
		}
		if (u < 0) u += mod;
		return u;
	}
				
};
using mint =ModInt<998244353>;
void solve(){
	long long n,m;cin>>n>>m;
	vector<long long>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	vector<long long>f;
	vector<long long>p;
	for(long long i=2;i*i<=m;i++){
		if(m%i==0){
			long long res=1;
			while(m%i==0){
				res*=i;
				m/=i;
			}
			f.push_back(res);
			p.push_back(i);
		}
	}
	if(m!=1){
		f.push_back(m);
		p.push_back(m);
	}
	int num=f.size();
	vector<long long>cnt((1ll<<num)+1);
	for(int i=1;i<=n;i++){
		long long val=0;
		for(int j=0;j<num;j++){
			if(a[i]%f[j]==0){
				a[i]/=f[j];
				if(a[i]%p[j]==0)break;
				val|=(1ll<<j);
			}
			while(a[i]%p[j]==0)a[i]/=p[j];
		}
		if(a[i]==1){
			cnt[val]++;
		}
	}
	vector<mint>pw(n+1);
	pw[0]=1;
	for(int i=1;i<=n;i++)pw[i]=pw[i-1]*2;
	vector<mint>dp((1ll<<num)+1);
	dp[0]=pw[cnt[0]];
	for(int i=1;i<(1ll<<num);i++){
		for(int j=(1ll<<num)-1;j>=0;j--){
			dp[i|j]=dp[i|j]+dp[j]*(pw[cnt[i]]-1);
		}
	}
	if(!num)dp[(1ll<<num)-1]-=1;
	cout<<dp[(1ll<<num)-1]<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}