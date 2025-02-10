#include<bits/stdc++.h>
#define int long long
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
void solve(){
    int n, m, k; cin >> n >> m >> k;
    vector<array<int, 4>>edge(m);
    for(int i = 0 ; i < m; i++){
    	int u, v, w, c;
    	cin >> u >> v >> w >> c;
    	edge[i] = {w, c, u, v};
    }
    auto check = [&](int x) -> pair<int ,int>{
    	int cnt = 0, sum = 0;
    	for(auto &[w, c, u, v] : edge){
    		if(c == 0){
    			w += x;
    		}
    	}
    	vector<int> f(n + 1);
    	for(int i = 1; i <= n; i++) f[i] = i;
    	auto find = [&](auto self, int x) -> int{
    		return f[x] == x ? x : f[x] = self(self, f[x]);
    	};
    	sort(edge.begin(), edge.end());
    	for(auto [w, c, u, v] : edge){
    		int fa = find(find, u);
    		int fb = find(find, v);
    		if(fa == fb)continue;
    		f[fa] = fb;
    		if(!c)cnt++;
    		sum += w;
    	}
    	sum -= k * x;
    	for(auto &[w, c, u, v] : edge){
    		if(c == 0){
    			w -= x;
    		}
    	}
    	return {cnt, sum};
    };
    int ans = -1;
    int l = -100, r = 100;
    while(l <= r){
    	int mid = (l + r) >> 1;
    	auto [cnt, sum] = check(mid);
    	if(cnt >= k){
    		ans = sum;
    		l = mid + 1;
    	}else r = mid - 1;
    }
    cout << ans << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}