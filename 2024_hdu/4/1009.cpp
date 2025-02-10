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
int p[13] = {0,31,29,31,30,31,30,31,31,30,31,30,31};
void solve(){
	int n, m; cin >> n >> m;
	string s; cin >> s;
	s = ' ' + s;
	vector<int> cnt(m + 5);
	vector last(10, vector<int>(m + 1));
	vector nex(30, vector<int>(m + 1));
	for(int i = 1; i <= m; i++){
		for(int j = 0; j <= 9; j++){
			last[j][i] = last[j][i - 1];
		}
		if(s[i] >= '0' && s[i] <= '9'){
			last[s[i] - '0'][i] = i;
		}
		// for(int j = 0; j <= 9; j++){
		// 	cout << last[j][i] << ' ';
		// }
		// cout << '\n';
	}
	for(int i = m; i >= 1; i--){
		for(int j = 0; j < 26; j++){
			nex[j][i] = nex[j][i + 1];
		}
		if(s[i] >= 'a' && s[i] <= 'z'){
			nex[s[i] - 'a'][i] = i;
		}
	}
	auto jump1 = [&](vector<int> &x) -> void{
		int l = m;
		int now = 3;
		while(l >= 0 && now >= 0){
			l = last[x[now]][l] - 1;
			now--;
		}
		if(l >= 0){
			cnt[1]++;
			cnt[l + 1]--;
		}
	};
	for(int i = 1; i <= 12; i++){
		vector<int>res(4);
		res[0] = i / 10 % 10;
		res[1] = i % 10;
		res[2] = 0;
		res[3] = 1;
		for(int j = 1; j <= p[i]; j++){
			jump1(res);
			res[3]++;
			if(res[3] >= 10){
				res[3] = 0;
				res[2]++;
			}
		}
	}
	for(int i = 1; i <= m; i++)cnt[i] += cnt[i - 1];
	long long ans = 0;
	auto jump2 = [&](string &x) -> void{
		int r = 1;
		for(auto i : x){
			r = nex[i - 'a'][r];
			if(r == 0)break;
			r++;
		}
		ans += cnt[r];
	};
	for(int i = 1; i <= n; i++){
		string x; cin >> x;
		jump2(x);
	}
	cout << ans << '\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}