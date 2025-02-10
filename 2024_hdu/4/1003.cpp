#include<bits/stdc++.h>
//#define int long long
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
constexpr int maxn = 2e5 + 5;
bool vis[maxn];
vector<int>prim;
void init(){
	vis[1] = 1;
	for(int i = 2; i < maxn; i++){
		if(!vis[i])prim.push_back(i);
		for(int j = 0; i * prim[j] < maxn; j++){
			vis[i * prim[j]] = 1;
			if(i % prim[j] == 0) break;
		}
	}
}
void solve(){
	int n, k; cin >> n >> k;
	vector<int> a(n + 1);
	vector<int>pre(n + 1);
	int l = 0, r = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i] < 0)l += a[i];
		else r += a[i];
		pre[i] = pre[i - 1] + a[i];
	}
	int ans = -1;
	int num = 20;
	auto check = [&](int x) -> bool{
		set<pair<int, int>>s;
		int cnt = 0;
		s.insert({0, 0});
		for(int i = 1; i <= n; i++){
			int ok = 0;
			if(!s.empty()){
				int f = 0;
				for(auto [l, r] : s){
					if(f > num || ok)break;
					if(!vis[i - r] && pre[i] - l >= x){
						ok = 1;
						break;
					}
					f++;
				}
			}
			if(ok){
				s.clear();
				cnt++;
			}
			s.insert({pre[i], i});
		}
		return cnt >= k;
	};
	while(l <= r){
		int mid = (l + r) >> 1;
		if(check(mid)){
			ans = mid;
			l = mid + 1;
		}else r = mid - 1;
	}
	if(ans == -1)cout << "impossible\n";
	else{
		cout << ans << '\n';
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	init();
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}