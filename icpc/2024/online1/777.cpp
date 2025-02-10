#include <bits/stdc++.h>

using namespace std;
#define int long long
#define dbg(x...) \
do{ \
	cout << #x << " -> "; \
	err(x); \
}while(0)
void err(){
	cout << endl << endl;
}
template<class T, class ... Ts>
void err(T arg, Ts ...args){
	cout << fixed << setprecision(10) << arg << ' ';
	err(args...);
}
void solve() {
	int n; cin >> n;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i++) cin >> a[i];
	vector<int> p;
	for(int i = 1; i <= n; i++){
		p.push_back(a[i]);
	}
	sort(p.begin(), p.end());
	p.erase(unique(p.begin(), p.end()), p.end());
	auto get = [&](int x) -> int{
		return lower_bound(p.begin(), p.end(), x) - p.begin();
	};
	for(int i = 1; i <= n; i++){
		a[i] = get(a[i]);
	}
	// for(int i = 1; i <= n; i++){
	// 	cout << a[i] << ' ';
	// }
	// cout << endl;
	vector b(n + 1, vector<int>(n + 1));
	for(int i = 1; i <= n; i++){
		priority_queue<int>q1;
		priority_queue<int, vector<int>, greater<int>>q2;
		for(int j = i; j <= n; j++){
			if(q1.size() == q2.size()){
				q2.push(a[j]);
				q1.push(q2.top());
				q2.pop();
			}else{
				assert(q1.size() == q2.size() + 1);
				q1.push(a[j]);
				q2.push(q1.top());
				q1.pop();
			}
			b[i][j] = q1.top();
			//dbg(i, j, b[i][j]);
		}
	}
	vector cnt(n + 1, vector<int>(n + 1));
	auto check = [&](int x) -> bool{
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				cnt[i][j] = 0;
			}
		}
		for(int i = 1; i <= n; i++){
			for(int j = i; j <= n; j++){
				if(b[i][j] >= x)cnt[i][j] = 1;
				else cnt[i][j] = 0;
			}
		}
		for(int i = 1; i <= n; i++){
			for(int j = i; j <= n; j++){
				cnt[i][j] += cnt[i - 1][j];
			}
		}
		int res = 0;
		int tot = 0;
		for(int i = 1; i <= n; i++){
			int c1 = 0;
			int num = 0;
			for(int j = i; j <= n; j++){
				tot++;
				int len = j - i + 1;
				num += j - i + 1;
				c1 += cnt[j][j] - cnt[i - 1][j];
				
				if(c1 >= (num + 1) / 2)res++;
			}
		}
		dbg(res, tot);
		if(res >= (tot + 1) / 2)return true;
		else return false;
	};
	int ans = 0;
	int l = 0, r = p.size() - 1;
	while(l <= r){
		int mid = (l + r) / 2;
		//dbg(l, r, mid);
		if(check(mid)){
			ans = mid;
			l = mid + 1;
		}else r = mid - 1;
	}
	cout << p[ans] << '\n';
	return ;
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T = 1;
	//cin >> T;
	while(T--) solve();
	return 0;
}