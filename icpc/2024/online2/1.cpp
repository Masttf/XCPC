#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do{ \
	cout << #x << " -> "; \
	err(x); \
}while(0)
void err(){
	cout << endl << endl;
}
template<class T, class ...Ts>
void err(T arg, Ts ...args){
	cout << fixed << setprecision(10) << arg << ' ';
	err(args...);
}

const int maxn = 1e5 + 5;
vector<int> Team[maxn];

void solve(){
	int n,k;cin >> n >> k;
	vector<int>c(k + 5);
	int mi = 1e9;
	for (int i = 1;i <= k;i++) {
		cin >> c[i];
		mi = min(mi, c[i]);
	}
	unordered_map<string,int>mp;
	int now = 1;
	vector<int>w(n + 5);
	vector<int>group(n + 5);
	for (int i = 1;i <= n;i++) {
		string s;
		cin >> w[i] >> s;
		if (!mp[s]) {
			mp[s] = now++;
		}
		group[i] = mp[s];
		Team[group[i]].push_back(w[i]);
	}
	vector<int>val;
	for (int i = 1;i <= now - 1;i++) {
		sort(Team[i].begin(),Team[i].end(),greater<>());
		for (int j = 0;j < min((int)Team[i].size(),mi);j++) {
			val.push_back(Team[i][j]);
		}
	}
	sort(val.begin(),val.end());
	// cout << val.size() << '\n';
	// for (auto i : val) dbg(i);
	for (int i = 1;i <= n;i++) {
		int place = lower_bound(val.begin(),val.end(),w[i]) - val.begin();
		//dbg(place);
		if (val[place] == w[i]) {
			int ans = val.size() - place;
			cout << ans << '\n';
		}
		else {
			int st = group[i];
			int v = Team[st][mi];
			int ans = val.size() - place;
			cout << ans << '\n';
		}
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while(t--)solve();
	return 0;
}