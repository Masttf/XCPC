#include<bits/stdc++.h>
#define int long long
#define lowbit(x) ((x)&-(x))
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
using mint =ModInt<1000000007>;
		
void solve(){
	int n,m,k;cin>>n>>m>>k;
	mint ans=0;
	auto get = [&](int x)->int{
		int res=0;
		while(x){
			res++;
			x-=lowbit(x);
		}
		return res;
	};
	// for(int s=0;s<(1<<m);s++){
	// 	if(get(s)>k)continue;
	// 	vector dp(n+1,vector<mint>(1<<m));
	// 	dp[0][s]=1;
	// 	for(int i=1;i<=n;i++){
	// 		for(int j=0;j<(1<<m);j++){
	// 			int d=get(j);
	// 			if(d>k)continue;
	// 			dp[i][j]+=dp[i-1][j>>1];
	// 			dp[i][j]+=dp[i-1][(j>>1)|(1<<(m-1))];
	// 		}
	// 	}
	// 	ans+=dp[n][s];
	// 	dbg(s,ans);
	// }
	vector p((1<<m),vector<mint>(1<<m));
	for(int j=0;j<(1<<m);j++){
		int d=get(j);
		if(d>k)continue;
		p[j>>1][j]=1;
		p[(j>>1)|(1<<(m-1))][j]=1;
	}
	auto mul = [&](vector<vector<mint>>x,vector<vector<mint>>y)->vector<vector<mint>>{
		vector<vector<mint>>res(x.size(),vector<mint>(y[0].size()));
		for(int i=0;i<x.size();i++){
			for(int j=0;j<y[0].size();j++){
				for(int k=0;k<x[i].size();k++){
					res[i][j]+=x[i][k]*y[k][j];
				}
			}
		}
		return res;
	};
	auto qmi = [&](vector<vector<mint>>a,int b)->vector<vector<mint>>{
		vector res(a.size(),vector<mint>(a[0].size()));
		for(int i=0;i<a.size();i++){
			res[i][i]=1;
		}
		while(b){
			if(b&1)res=mul(res,a);
			b>>=1;
			a=mul(a,a);
		}
		return res;
	};
	// vector<vector<mint>>t1={{1,1},{1,0}};
	// vector<vector<mint>>t2={{1,1}};
	// vector<vector<mint>>t3=mul(t2,qmi(t1,1));
	// for(int i=0;i<t3.size();i++){
	// 	for(int j=0;j<t3[i].size();j++){
	// 		cout<<t3[i][j]<<' ';
	// 	}
	// 	cout<<endl;
	// }
	vector<vector<mint>>res=qmi(p,n);
	for(int s=0;s<(1<<m);s++){
		if(get(s)>k)continue;
		vector temp(1,vector<mint>(1<<m));
		temp[0][s]=1;
		temp=mul(temp,res);
		ans+=temp[0][s];
		//dbg(s,ans);
	}
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