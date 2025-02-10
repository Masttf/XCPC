#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
	cout << #x << " -> "; \
	err(x); \
} while (0)
 
void err() {
	cout << endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
	cout << fixed << setprecision(10) << arg << ' ';
	err(args...);
}
template<const int T>
struct ModInt {
	const static int mod = T;
	int x;
	ModInt(int x = 0) : x(x % mod) {}
	//ModInt(long long x) : x(int(x % mod)) {} 
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
	int n,k;cin>>n>>k;
	string s;cin>>s;
	s=' '+s;
	for(int i=1;i<=n;i++){
		if(s[i]=='A')s[i]='0';
		else if(s[i]=='B')s[i]='1';
	}
	//dbg(s);
	vector dp(n+1,vector<mint>(1ll<<k));
	dp[0][0]=1;
	auto check = [&](int x)->bool{
		for(int i=0;i<k;i++){
			if((x>>i&1)!=(x>>(k-i-1)&1))return true;
		}
		return false;
	};
	//dbg(check(6));
	for(int i=1;i<=n;i++){
		if(s[i]=='?'){
			if(i<k){
				for(int s=0;s<(1ll<<k);s++){
					int j=s>>1;
					dp[i][s]+=dp[i-1][j];
				}
			}else{
				for(int s=0;s<(1ll<<k);s++){
					if(!check(s))continue;
					int j=s>>1;
					int d=s;
					if(s>>(k-1)&1)d-=1<<(k-1);
					dp[i][d]+=dp[i-1][j];
				}
			}
		}else if(s[i]=='0'){
			if(i<k){
				for(int s=0;s<(1ll<<k);s++){
					if(!(s&1)){
						int j=s>>1;
						dp[i][s]+=dp[i-1][j];
						//dbg(i,s,dp[i][s]);
					}
				}
			}else{
				for(int s=0;s<(1ll<<k);s++){
					if(!check(s))continue;
					if(!(s&1)){
						int j=s>>1;
						int d=s;
						if(s>>(k-1)&1)d-=1<<(k-1);
						dp[i][d]+=dp[i-1][j];
					}
				}
			}
		}else{
			if(i<k){
				for(int s=0;s<(1ll<<k);s++){
					if(s&1){
						int j=s>>1;
						dp[i][s]+=dp[i-1][j];
						//dbg(i,s,dp[i][s]);
					}
				}
			}else{
				for(int s=0;s<(1ll<<k);s++){
					if(!check(s))continue;
					if(s&1){
						int j=s>>1;
						int d=s;
						if(s>>(k-1)&1)d-=1<<(k-1);
						dp[i][d]+=dp[i-1][j];
					}
				}
			}
		}
		// for(int j=0;j<(1ll<<(k-1));j++){
		// 	dbg(i,j,dp[i][j]);
		// }
	}
	mint ans=0;
	for(int i=0;i<(1<<(k-1));i++)ans+=dp[n][i];
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}