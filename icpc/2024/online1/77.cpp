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
	vector b(n + 1, vector<int>(n + 1, 0));
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
		}
	}
	vector cnt(n + 1, vector<int>(n + 1, 0));
	auto check = [&](int x) -> bool{
		cnt.assign(n + 1, vector<int> (n + 1, 0));
		for(int i = 1; i <= n; i++){
			for(int j = i; j <= n; j++){
				if(b[i][j] <= x)cnt[i][j] = 1;
				else cnt[i][j] = 0;
			}
		}
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				cnt[i][j] += cnt[i - 1][j] + cnt[i][j - 1] - cnt[i - 1][j - 1];
			}
		}
		auto get_c = [&](int x1, int y1, int x2, int y2) -> int{
			return cnt[x2][y2] - cnt[x1 - 1][y2] - cnt[x2][y1 - 1] + cnt[x1 - 1][y1 - 1];
		};
		int res = 0;
		int tot = (n + 1) * n / 2;
		for(int i = 1; i <= n; i++){
			for(int j = i; j <= n; j++){
				int len = j - i + 1;
				int num = (len + 1) * len / 2;
				int c1 = get_c(i, i, j, j);
				
				if(c1 >= (num + 1) / 2)res++;
			}
		}
		if(res >= (tot + 1) / 2)return true;
		else return false;
	};
	int ans = 0;
	int l = 0, r = p.size() - 1;
	while(l <= r){
		int mid = (l + r) >> 2;
		if(check(mid)){
			ans = mid;
			r = mid - 1;
		}else l = mid + 1;
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