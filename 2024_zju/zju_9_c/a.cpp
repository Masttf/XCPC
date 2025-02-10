#include<bits/stdc++.h>
#define int long long
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
struct node{
	int l, r, val;
};
constexpr int Max = 1e18;
void solve(){
	int n; cin >> n;
	vector<int> a(n + 1);
	vector<int> p;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		p.push_back(a[i]);
	}
	a[0] = a[1];
	sort(p.begin(), p.end());
	p.erase(unique(p.begin(), p.end()), p.end());
	auto get = [&](int x) -> int{
		return lower_bound(p.begin(), p.end(), x) - p.begin() + 1;
	};
	vector<node> tr(n * 32);
	vector<int> root(n + 1);
	int tot = 0;
	auto updata = [&](auto self, int &u, int v, int l, int r, int x) -> void{
		u = ++tot;
		tr[u] = tr[v];
		tr[u].val++;
		if(l == r)return ;
		int mid = (l + r) >> 1;
		if(x <= mid)self(self, tr[u].l, tr[v].l, l, mid, x);
		else self(self, tr[u].r, tr[v].r, mid+1, r, x);
	};
	auto query = [&](auto self, int u, int v, int l, int r, int x, int y) -> int{
		if(x <= l && r <= y)return tr[u].val - tr[v].val;
		int res = 0;
		int mid = (l + r) >> 1;
		if(x <= mid)res += self(self, tr[u].l, tr[v].l, l, mid, x, y);
		if(y > mid)res += self(self, tr[u].r, tr[v].r, mid+1, r, x, y);
		return res;
	};
	for(int i = 1; i <= n; i++){
		updata(updata, root[i], root[i-1], 1, n, get(a[i]));
	}
	vector<pair<int, int>> dp(n + 1);
	auto check = [&](int x) -> bool{
		dp[1] = {1, 1};
		for(int i = 2; i <= n; i++){
			auto [ll, rr] = dp[i - 1];
			int rL = -1, rR = -1;
			if(abs(a[i] - a[i - 1]) <= x)
				rL = ll, rR = rr;
			int l = get(a[i] - x);
			int r = upper_bound(p.begin(), p.end(), a[i] + x) - p.begin();
			//dbg(l, r, a[i] + x, a[i]);
			r = min(n, r);
			if(query(query, root[rr], root[ll - 1], 1, n, l, r))
				rR = i - 1;
			if(rL == -1)rL = rR;
			dp[i] = {rL, rR};
			if(rR == -1)return false;
		}
		return true;
	};
	int l = 0, r = 1e9;
	int ans = r;
	while(l <= r){
		int mid = (l + r) >> 1;
		if(check(mid)){
			ans = mid;
			r = mid - 1;
		}else l = mid + 1;
	}
	cout << ans << '\n';
	check(ans);
	vector<int> res(n + 1);
	vector<int> last(2, -1);
	res[n] = 1;
	last[1] = a[n];
	for(int i = n; i >= 2; i--){
		auto [l, r] = dp[i];
		//dbg(i, l, r);

		int j = i - 1;
		if(r != i - 1){
			res[j] = res[i];
		}else{
			auto [ll, rr] = dp[i - 1];
			j = rr;
			while(j >= ll){
				if(abs(a[j] - a[i]) <= ans)break;
				j--;
			}
			assert(j >= ll);
			for(int k = j + 1; k <= i-1; k++){
				res[k] = res[i] ^ 1;
				// if(last[res[k]] != -1)
				// 	assert(abs(a[k] - last[res[k]]) <= ans);
				last[res[k]] = a[k];
			}
			res[j] = res[i];
			// if(last[res[j]] != -1)
			// 	assert(abs(a[j] - last[res[j]]) <= ans);
			last[res[j]] = a[j];
			i = j + 1;
		}
		
	}
	for(int i = 2; i <= n; i++){
		if(res[i])cout << 'R';
		else cout << 'L';
	}
	cout << '\n';
	deque<int> q;
	int sum = 0;
	q.push_back(a[1]);
	for(int i = 2; i <= n; i++){
		if(res[i])q.push_back(a[i]);
		else q.push_front(a[i]);
	}
	for(int i = 1; i < n; i++){
		int u = q.front();
		q.pop_front();
		sum = max(sum, abs(u - q.front()));
	}
	//assert(sum == ans);
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}
