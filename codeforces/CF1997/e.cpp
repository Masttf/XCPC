#include<bits/stdc++.h>
//#define int long long
#define lowbit(x) ((x) & -(x))
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
void solve(){
	int n, q; cin >> n >> q;
	vector<int>a(n + 1);
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	vector res(n + 1, vector<pair<int, int>>());
	for(int i = 1; i <= q; i++){
		int x, k; cin >> x >> k;
		res[k].push_back({x, i});
	}
	int block = sqrt(n);
	vector pre(block + 1, vector<int>(n + 1));
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= block; j++)pre[j][i] = pre[j][i - 1];
		if(a[i] >= block){
			pre[block][i]++;
		}else{
			for(int j = a[i]; j <= block; j++)pre[j][i]++;
		}

	}
	for(int i = 1; i <= n; i++)sort(res[i].begin(), res[i].end());
	vector<int>ans(q + 1);
	for(int i = 1; i <= n; i++){
		int now = 1;
		int ll = 1;
		vector<pair<int, int>>stk;
		if(n / i > block){
			int cnt = 0;
			for(int j = 1; j <= n; j++){
				if(a[j] >= now)cnt++;
				if(cnt == i){
					stk.push_back({j, now});
					now++;
					cnt = 0;
				}
			}
			stk.push_back({n + 2, now});
		}else{
			while(ll <= n){
				int l = ll + i - 1, r = n;
				int tp = -1;
				while(l <= r){
					int mid = (l + r) >> 1;
					int d = pre[block][mid] - pre[now - 1][mid] - (pre[block][ll - 1] - pre[now -1][ll - 1]);
					if(d >= i){
						tp = mid;
						r = mid - 1; 
					}else l = mid + 1;
				}
				if(tp == -1)tp = n + 1;
				now++;
				ll = tp + 1;
				stk.push_back({tp, now -1});
			}
		}
		
		// for(auto [l, r] : stk){
		// 	dbg(i, l, r);
		// }
		int sz = 0;
		for(auto [x, id] : res[i]){
			while(x > stk[sz].first)sz++;
			if(a[x] >= stk[sz].second){
				//dbg(x, a[x], stk[sz].second, id);
				ans[id] = 1;
			}
		}
	}
	for(int i = 1; i <= q; i++){
		if(ans[i])cout << "YES\n";
		else cout << "NO\n";
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}