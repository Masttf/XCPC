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
template<const int T>
struct ModInt {
	const static int mod = T;
	int x;
	ModInt(int x = 0) : x(x % mod) {}
	// ModInt(long long x) : x(int(x % mod)) {} 
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
	}
	bool operator != (const ModInt &a) const {
		return x != a.x;
	}
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
constexpr int Max = 1e18;
using pii = pair<int, int>;
void solve(){
    int n, m, k; cin >> n >> m >> k;
    vector<vector<pair<int, int>>>g(n + 1);
    for(int i = 1; i <= m; i++){
    	int u, v, w; cin >> u >> v >> w;
    	g[u].push_back({v, w});
    	g[v].push_back({u, w});
    }
    int M = n + 10;
    // int M = 100;
    vector dis(n + 1, vector<pair<int, int>>(M + 1, {Max, Max}));
    vector vis(n + 1, vector<bool>(M + 1));
    auto dij = [&]() -> void{
    	priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>>q;
    	dis[1][0] = {0, Max};
    	q.push({0, 0, 1});
    	while(!q.empty()){
    		auto [ww, limit, u] = q.top();
    		q.pop();
    		if(vis[u][limit])continue;
    		vis[u][limit] = 1;
    		if(limit == M)continue;
    		for(auto [v, w] : g[u]){
    			if(dis[v][limit + 1].first > ww + w){
    				dis[v][limit + 1].first = ww + w;
    				dis[v][limit + 1].second = min(w, dis[u][limit].second);
    				q.push({dis[v][limit + 1].first, limit + 1, v});
    			}
    		}
    	}
    };
    dij();
    mint ans = 0;
    for(int i = 1; i <= min(M, k); i++){
    	if(dis[n][i].first == Max)continue;
    	ans += dis[n][i].first;
    	// dbg(i, dis[n][i].first, dis[n][i].second);
    }
    // dbg(ans);s
    if(k > M && dis[n][M].first != Max){
    	int temp = (k - M) / 2;
	    int cost = dis[n][M].second * 2;
	    // dbg(temp, dis[n][M].first, cost);
	    ans += dis[n][M].first * mint(temp);
	    ans += (1 + temp) * (temp) / 2 * mint(cost);
    }
    M--;
    // dbg(ans, M);
    if(k > M && dis[n][M].first != Max){
    	int temp = (k - M) / 2;
	    int cost = dis[n][M].second * 2;
	    ans += dis[n][M].first * mint(temp);
	    ans += (1 + temp) * (temp) / 2 * mint(cost);
    }
    cout << ans << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}