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
	int n,k,M;cin >> n >> k >> M;
	vector<string>s(n + 5);
	for (int i = 1;i <= n;i++) {
		cin >> s[i];
		//dbg(s[i]);
	}
	vector<int>p(15);
	p[0] = 1;
	for (int i = 1;i <= k;i++) p[i] = p[i - 1] * 3;
	vector<int>dp(p[k] + 5,-1);
	dp[0] = 1;
	for (int i = 1;i <= n;i++) {
		auto f = dp;
		dp.assign(p[k] + 5,-1);
		for (int j = 0;j < p[k];j++) {
			int sum = 0;
			for (int z = 0;z < k;z++) {
				char now = s[i][z];
				int val = j / p[z] % 3;
				if (now == '+') {
					val = (val + 1) % 3;
				}
				else if (now == '-') {
					val = (val - 1 + 3) % 3;
				}
				sum += val * p[z];
			}
			if (f[j] != -1) {
				//dbg(i,j,sum);
				if (dp[sum] == -1) dp[sum] = 0;
				dp[sum] = (dp[sum] + f[j]) % M;
			}
			if (f[j] != -1) {
				//dbg(i,j,sum);
				if (dp[j] == -1) dp[j] = 0;
				dp[j] = (dp[j] + f[j]) % M;
			}
		}
	} 
	vector<pair<string,int>>res;
	for (int i = 0;i < p[k];i++) {
		if (dp[i] == -1) continue;
		string now;
		for (int z = 0;z < k;z++) {
			int val = i / p[z] % 3;
			if (val == 0) now += "A";
			else if (val == 1) now += "B";
			else now += "C";
		}
		res.push_back({now,dp[i]});
	}
	sort(res.begin(),res.end());
	for (auto i : res) {
		cout << i.first << ' ' << i.second % M << '\n';
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}