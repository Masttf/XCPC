#include<bits/stdc++.h>
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
const int mod=1e9+7;
using mint =ModInt<mod>;

void solve(){
	string s;cin>>s;
	int n=s.size();
	s=' '+s;
	vector pdp(2,vector (5,vector<mint>(n+5)));
	vector sdp(2,vector (5,vector<mint>(n+5)));
	pdp[0][0][0]=1;
	sdp[0][0][n+1]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=2;j++){
			pdp[1][j][i]=pdp[0][j][i-1];
		}
		if(s[i]=='m'){
			for(int j=0;j<=2;j++){
				pdp[0][1][i]+=pdp[0][j][i-1]+pdp[1][j][i-1];
			}
		}else if(s[i]=='y'){
			pdp[0][2][i]=pdp[0][1][i-1]+pdp[1][1][i-1];
			for(int j=0;j<=2;j++){
				if(j==1)continue;
				pdp[0][0][i]+=pdp[0][j][i-1]+pdp[1][j][i-1];
			}
		}else{
			for(int j=0;j<=2;j++){
				pdp[0][0][i]+=pdp[0][j][i-1]+pdp[1][j][i-1];
			}
		}
	}
	// for(int i=1;i<=n;i++){
	// 	for(int j=0;j<=4;j++){
	// 		dbg(i,j,pdp[0][j][i]);
	// 	}
	// }
	for(int i=n;i>=1;i--){
		for(int j=0;j<=2;j++){
			sdp[1][j][i]=sdp[0][j][i+1];
		}
		if(s[i]=='o'){
			for(int j=0;j<=2;j++){
				sdp[0][1][i]+=sdp[0][j][i+1]+sdp[1][j][i+1];
			}
		}else if(s[i]=='g'){
			sdp[0][2][i]=sdp[0][1][i+1]+sdp[1][1][i+1];
			for(int j=0;j<=2;j++){
				if(j==1)continue;
				sdp[0][0][i]+=sdp[0][j][i+1]+sdp[1][j][i+1];
			}
		}else{
			for(int j=0;j<=2;j++){
				sdp[0][0][i]+=sdp[0][j][i+1]+sdp[1][j][i+1];
			}
		}
	}
	
	mint ans=0;
	for(int i=1;i<=n;i++){
		if(s[i]!='y')continue;
		mint temp=ans;
		ans+=pdp[0][2][i]*sdp[0][2][i+1];
		ans+=pdp[0][2][i]*sdp[1][2][i+1];
		mint d=ans-temp;
		//dbg(i,d);
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