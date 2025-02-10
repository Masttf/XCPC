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

void solve(){
	int k;cin >> k;
	string s;cin >> s;
	if (k <= 20) {
		cout << "YES" << '\n';
		return ;
	}
	vector<int>g(11,0);
	deque<int>q;
	for (int i = 1;i <= 10;i++) q.push_back(i);
	for (int i = 1;i <= k;i++) {
		int now = (i - 1) % 5 + 1;
		now--;
		//dbg(now);
		if (s[i - 1] == '0') {
				g[q[10 - now - 1]]++;
			}
			else {
				g[q[now]]++;
			}
		if (i % 5 == 0) {
			q.pop_front();
			q.push_front(q.back());
			q.pop_back();
			q.push_front(1);
		}
	}
	int sy = 45 - k;
	int cnt = k;
	vector<int>vis;
	for (int i = k + 1;i <= 45;i++) {
		if ((i - 1) % 5 == 0) {
			int now1 = i - k;
			//cout << sy - now1 << ' ';
			vis.push_back(sy - now1);
		}
	}
	deque<int>q1(11);
	q1 = q;
	for (int i = 0;i < (1ll << sy);i++) {
		cnt = k;
		int ok = 0;
		for (auto j : vis) {
			if ((i >> j) & 1) continue;
			else {
				ok = 1;
				break;
			}
		}
		if (ok) continue;
		vector<int>v(11,0);
		for (int j = sy - 1;j >= 0;j--) {
			cnt++;
			int now = (cnt - 1) % 5 + 1;
			now--;
			if ((i >> j) & 1) {
				v[q[now]]++;
			}
			else v[q[10 - now - 1]]++;
			if (cnt % 5 == 0) {
				q.pop_front();
				q.push_front(q.back());
				q.pop_back();
				q.push_front(1);
			}
		}
		q = q1;
		vector<pair<int,int>>b(11);
		int res = g[1] + v[1];
		for (int j = 1;j <= 10;j++) {
			b[j].first = g[j] + v[j];
			b[j].second = j; 
		}
		sort(b.begin() + 1,b.begin() + 11);
		if (res >= b[7].first) {
			cout << "YES" << '\n';
			return ;
		}
	}
	cout << "NO" << '\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}