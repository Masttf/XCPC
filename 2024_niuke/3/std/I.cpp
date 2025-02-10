#include <bits/stdc++.h>
#define int long long
using namespace std;
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
const int N=200007;
const int B=6000;
int n;
string s;
int f[N],rf[N];
 
const ll mod = (119 << 23) + 1, root = 62; // = 998244353
// For p < 2^30 there is also e.g. 5 << 25, 7 << 26, 479 << 21
// and 483 << 21 (same root). The last two are > 10^9.
typedef vector<ll> vl;
 
int C(int u,int v){
    return f[u]*rf[v]%mod*rf[u-v]%mod;
}
ll modpow(ll b, ll e) {
	ll ans = 1;
	for (; e; b = b * b % mod, e /= 2)
		if (e & 1) ans = ans * b % mod;
	return ans;
}
 
void ntt(vl &a) {
	int n = sz(a), L = 31 - __builtin_clz(n);
	static vl rt(2, 1);
	for (static int k = 2, s = 2; k < n; k *= 2, s++) {
		rt.resize(n);
		ll z[] = {1, modpow(root, mod >> s)};
		rep(i,k,2*k) rt[i] = rt[i / 2] * z[i & 1] % mod;
	}
	vi rev(n);
	rep(i,0,n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
	rep(i,0,n) if (i < rev[i]) swap(a[i], a[rev[i]]);
	for (int k = 1; k < n; k *= 2)
		for (int i = 0; i < n; i += 2 * k) rep(j,0,k) {
			ll z = rt[j + k] * a[i + j + k] % mod, &ai = a[i + j];
			a[i + j + k] = ai - z + (z > ai ? mod : 0);
			ai += (ai + z >= mod ? z - mod : z);
		}
}
vl conv(const vl &a, const vl &b) {
	if (a.empty() || b.empty()) return {};
	int s = sz(a) + sz(b) - 1, B = 32 - __builtin_clz(s),
	    n = 1 << B;
	int inv = modpow(n, mod - 2);
	vl L(a), R(b), out(n);
	L.resize(n), R.resize(n);
	ntt(L), ntt(R);
	rep(i,0,n)
		out[-i & (n - 1)] = (ll)L[i] * R[i] % mod * inv % mod;
	ntt(out);
	return {out.begin(), out.begin() + s};
}
 
int solve(vector<int> &ans,int prv,int L,int R){
    if (L==R) return prv;
    int lb=n+6,rb=0,rprv=prv;
    for (int i=L;i<R;++i){
        if (s[i]=='1') rprv=i;
        lb=min(lb,i-rprv), rb=max(rb,i-rprv);
    }
    // uppper part
    vector<int> tmp(n-rb+1),binom(R-L+1);
    for (int i=0;i<=R-L;++i) binom[i]=C(R-L,i);
    for (int i=rb;i<=n;++i){
        tmp[i-rb]=ans[i];
    }
    auto ret=conv(tmp,binom);
    for (int i=rb;i<=n;++i) ans[i]=ret[i-rb];
    // middle part
    vector<int> lst(rb-lb+R-L);
    for (int i=lb;i<rb;++i) lst[i-lb]=ans[i], ans[i]=0;
    for (int i=L;i<R;++i){
        if (s[i]=='1') prv=i;
        int idx=i-prv-lb;
        for (int j=rb-lb+i-L-1;j>=idx;--j) lst[j+1]=(lst[j+1]+lst[j])%mod; 
    }
    for (int i=0;i<rb-lb+R-L;++i) {if (i+lb>n) break; ans[i+lb]=(ans[i+lb]+lst[i])%mod;}
    return prv;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n>>s;
    reverse(s.begin(), s.end());
    while (s.back()=='0') s.pop_back(), n--;
    reverse(s.begin(), s.end());
    f[0]=1;
    for (int i=1;i<N;++i) f[i]=f[i-1]*i%mod;
    rf[N-1]=modpow(f[N-1],mod-2);
    for (int i=N-1;i>0;--i) rf[i-1]=rf[i]*i%mod;
    vector<int> ans(n+1,0); ans[0]=1;
    int prv=0,pl=0,pret=0;
    for (int i=0;i<n;++i){
        if (s[i]=='1') {
            if (i-prv>B) {pret=solve(ans,pret,pl,i), pl=i;}
            prv=i;
        }
        if (i-pl>B){pret=solve(ans,pret,pl,i), pl=i;}
    }
    if (pl<n) solve(ans,pret,pl,n);
    int res=0;
    for (int i=0;i<=n;++i) res=(res+ans[i])%mod;
    cout<<res;
}
