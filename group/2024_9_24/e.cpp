#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
    cout << #x << " -> "; \
    err(x); \
} while (0)

void err() {
    cout << endl << endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
    cout << fixed << setprecision(10) << arg << ' ';
    err(args...);
}
template<const int mod>
struct ModInt {
	int x;
	ModInt(int x = 0) : x(x % mod) {}
	//ModInt(long long x) : x(int(x % mod)) {} 
	int val() { return x; }
	ModInt operator + (const ModInt &a) const { 
		int x0 = x + a.x;
		return ModInt(x0 < mod ? x0 : x0 - mod);
	}
	ModInt operator - (const ModInt &a) const {
		int x0 = x - a.x;
		return ModInt(x0 < 0 ? x0 + mod : x0);
	}
	ModInt operator * (const ModInt &a) const {
		return ModInt(1LL * x * a.x % mod);
	}
	ModInt operator / (const ModInt &a) const {
		return *this * a.inv();
	}
	bool operator == (const ModInt &a) const {
		return x == a.x;
	};
	bool operator != (const ModInt &a) const {
		return x != a.x;
	};
	void operator += (const ModInt &a) {
		x += a.x;
		if (x >= mod) x -= mod;
	}
	void operator -= (const ModInt &a) {
		x -= a.x;
		if (x < 0) x += mod;
	}
	void operator *= (const ModInt &a) {
		x = 1LL * x * a.x % mod;
	}			
	void operator /= (const ModInt &a) {
		*this = *this / a;
	}
	friend ModInt operator + (int y, const ModInt &a){
		int x0 = y + a.x;
		return ModInt(x0 < mod ? x0 : x0 - mod);
	}
	friend ModInt operator - (int y, const ModInt &a){
		int x0 = y - a.x;
		return ModInt(x0 < 0 ? x0 + mod : x0);
	}			
	friend ModInt operator * (int y, const ModInt &a){
		return ModInt(1LL * y * a.x % mod);
	}
	friend ModInt operator / (int y, const ModInt &a){
		return ModInt(y) / a;
	}
	friend ostream &operator<<(ostream &os, const ModInt &a) {
		return os << a.x;
	}
	friend istream &operator>>(istream &is, ModInt &t){
		return is >> t.x;
	}						
				
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
constexpr int mod = 998244353;
using mint =ModInt<mod>;
void solve(){
    int n, m, s, p; cin >> n >> m >> s >> p;
    vector<vector<int>>g(n + 1);
    vector<int>du(n + 1);
    for(int i = 1; i <= m; i++){
    	int u, v; cin >> u >> v;
    	g[u].push_back(v);
    	du[v]++;
    }
    vector<int>d(n + 1);
    vector<int> vis(n + 1);
    {
    	queue<int>q;
    	q.push(s);
    	vis[s] = 1;
    	while(!q.empty()){
    		int u = q.front();
    		q.pop();
    		for(auto v : g[u]){
    			if(vis[v])continue;
    			vis[v] = 1;
    			d[v] = d[u] + 1;
    			q.push(v);
    		}
    	}
    }
    vector<int>ans1(n + 1), ans2(n + 1);
    vector<int>can(n + 1);
    for(int i = 1; i <= n; i++){
    	if(!vis[i]){
    		for(auto v :g[i]){
    			du[v]--;
    		}
    	}
    }
    for(int i = 1; i <= n; i++){
    	if(du[i] == 1)can[i] = 1;
    }
    for(int i = 1; i <= n; i++){
    	if(!vis[i]){
    		for(auto v :g[i]){
    			du[v]++;
    		}
    	}
    }
    {
    	vector<int>cnt(n + 1);
    	queue<int>q;
    	for(int i = 1; i <= n; i++){
    		if(du[i] == 0)q.push(i);
    	}
    	while(!q.empty()){
    		int u = q.front();
    		if(cnt[u] >= 2)ans2[u] = 0;
    		q.pop();
    		for(auto v : g[u]){
    			du[v]--;
    			if(can[u]){
    				cnt[v]++;
    				ans2[v] = max({ans2[u], ans2[v], ans1[u]});
    			}
    			if(can[v])ans1[v] = max(ans1[v], p - d[v]);
    			if(!du[v])q.push(v);
    		}
    	}
    }
    for(int i = 1; i <= n; i++){
    	cout << max(ans1[i], ans2[i]) << ' ';
    }
    cout << endl;
    mint res = 0;
    for(int i = 1; i <= n; i++)res += max(ans1[i], ans2[i]);
    res = res * mint(n).inv();
	cout << res << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;// cin >> t;
    while(t--)solve();
    return 0;
}