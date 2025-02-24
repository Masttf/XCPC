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
pair<int, int> st[25][maxn];
void solve(){
	int n, q; cin >> n >> q;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i++)cin >> a[i];
	for(int i = 1; i <= n; i++){
		st[0][i] = {a[i], i};
	}
	for(int s = 1; s <= 20; s++){
		for(int i = 1; i + s -1 <= n; i++){
			st[s][i] = max(st[s - 1][i], st[s - 1][i + (1 << (s - 1))]);
		}
	}
	auto get_max = [&](int l, int r) -> pair<int, int>{
		int len = (r - l + 1);
		int d = __lg(len);
		return max(st[d][l], st[d][r - (1 << d) + 1]);
	};
	long long Ans = 0;
	for(int i = 1; i <= q; i++){
		int l, r; cin >> l >> r;
		pair<long long, int> ans = {0, 0};
		priority_queue<array<int, 4>>q;
		auto [v, id] = get_max(l, r);
		q.push({v, id, l, r});
		for(int k = 1; k <= 25; k++){
			if(q.empty())break;
			long long cnt = 0;
			int val = q.top()[0];
			while(!q.empty() && q.top()[0] == val){
				auto [vv, pp, ll, rr] = q.top();
				q.pop();
				cnt += 1ll * (pp - ll + 1) * (rr - pp + 1);
				if(pp > ll){
					auto [e, d] = get_max(ll, pp - 1);
					q.push({e, d, ll, pp - 1});
				}
				if(pp < rr){
					auto [e, d] = get_max(pp + 1, rr);
					q.push({e, d, pp + 1, rr});
				}
			}
			ans = max(ans, {cnt, val});
		}
		Ans ^= 1ll * ans.second * i;
	}
	cout << Ans << '\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}