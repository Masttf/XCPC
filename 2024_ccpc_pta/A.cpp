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
using Pii = std::pair<int, int>;

const int maxn = 1e6 + 5;
vector<int>prime;
int vis[maxn];

void get_prime() {
	for (int i = 2;i <= 1e6;i++) {
		if (!vis[i]) prime.push_back(i);
		for (int j = 0;j < (int)prime.size() && i * prime[j] <= 1e6;j++) {
			vis[i * prime[j]] = 1;
			if (i % prime[j] == 0) break;
		}
	}
}

void solve(){
	get_prime();
	int len = prime.size();
	set<int>s;
	for (int i = 0;i < len;i++) {
		for (int j = 0;j < i;j++) {
			s.insert(prime[i] - prime[j]);
		}
	}
	int cnt = 0;
	for (auto i : s) {
		cout << i << ' ';
		cnt++;
		if (cnt % 10 == 0) cout << '\n';
		if (cnt == 1000) break;
	}
}
signed main(){
	//ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}