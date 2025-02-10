#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int mod=998244353,maxn=1e5+5;
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
	friend ModInt operator + (int y, const ModInt &a){ int x0 = y + a.x; return ModInt(x0 < mod ? x0 : x0 - mod); }
	friend ModInt operator - (int y, const ModInt &a){ int x0 = y - a.x; return ModInt(x0 < 0 ? x0 + mod : x0); }
	friend ModInt operator * (int y, const ModInt &a){ return ModInt(1LL * y * a.x % mod);}
	friend ModInt operator / (int y, const ModInt &a){ return ModInt(y) / a;}
	friend ostream &operator<<(ostream &os, const ModInt &a) { return os << a.x;}
	friend istream &operator>>(istream &is, ModInt &t){return is >> t.x;}
	
	ModInt pow(LL n) const {
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
using mint = ModInt<998244353>;
mint pw[200],ppw[maxn][200];
void init(){
	pw[0]=1;
	for(int i=1;i<=124;i++){
		pw[i]=pw[i-1]*2;
	}
	for(int i=1;i<maxn;i++)ppw[i][0]=1;
	for(int i=1;i<maxn;i++){
		for(int j=1;j<=124;j++){
			ppw[i][j]=ppw[i][j-1]*i;
		}
	}
	return ;
}
void solve(){
	LL n,m;cin>>n>>m;
	vector<mint>cnt(125);
	cnt[1]=n;
	LL tot=0;
	LL temp=n;
	while(temp){
		temp/=2;
		tot++;
	}
	
	auto check =[&](LL x,LL now)->bool{
		LL temp=x*2;
		LL ct=now;
		while(temp<=n){
			ct++;
			temp<<=1;
		}
		LL res=ct;
		temp=x*2+1;
		ct=now;
		while(temp<=n){
			temp<<=1;
			temp++;
			ct++;
		}
		if(ct==res&&ct==tot)return 1;
		else return 0;
	};
	
	for(LL i=0;;i++){
		LL l=(1ll<<i);
		LL r=(1ll<<(i+1))-1;
		if(r>n)break;
		
		LL res=r+1;
		while(l<=r){
			LL mid=(l+r)>>1;
			if(check(mid,i+1))l=mid+1;
			else r=mid-1,res=mid;
		}
		l=(1ll<<i);
		r=(1ll<<(i+1))-1;
		LL num1=res-l;
		LL num2=r-res;
		LL num3=1;
		if(res>r)num3=0,num2=0;
		num2=(num2+num3)%mod;
		for(LL j=1;j<=tot-i-1;j++){
			for(LL k=1;k<=tot-i-1;k++){
				cnt[j+k+1]+=pw[j-1]*pw[k-1]*num1;
			}
		}
		for(LL j=1;j<=tot-i-1;j++){
			cnt[j+1]+=pw[j-1]*num1*2;
		}
		
		for(LL j=1;j<=tot-i-2;j++){
			for(LL k=1;k<=tot-i-2;k++){
				cnt[j+k+1]+=pw[j-1]*pw[k-1]*num2;
			}
		}
		for(LL j=1;j<=tot-i-2;j++){
			cnt[j+1]+=pw[j-1]*num2*2;
		}
		
		LL temp=2*res;
		while(temp<=n){
			temp<<=1;
		}
		if(temp==n+1)continue;
		temp/=2;
		LL d2=n-temp+1;
		cnt[tot-i]+=d2;
		if(check(res*2,i+2)){
			LL j=tot-i-1;
			LL d1=(1ll<<(j-1));
			for(LL k=1;k<=tot-i-2;k++){
				cnt[j+k+1]+=pw[j-1]*pw[k-1]*num3;
			}
			d2-=d1;
			//cout<<d1<<' '<<d2<<endl;
			for(LL k=1;k<=tot-i-1;k++){
				cnt[j+k+1]+=pw[k-1]*d2*num3;
			}
		}else{
			for(LL j=1;j<=tot-i-2;j++){
				cnt[tot-i+j]+=pw[j-1]*d2*num3;
			}
		}
	}
	mint ans=0;
	for(LL j=1;j<=124;j++){
		if(j>2*tot)break;
		if(n-j<0)break;
		mint temp=mint(m).pow(n-j);
		for(LL i=1;i<=m;i++){
			ans+=(ppw[i][j]-ppw[i-1][j])*temp*cnt[j]*i;
		}
	}
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	init();
	LL t;cin>>t;
	while(t--)solve();
	return 0;
}