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
	string s; cin >> s;
	int n = s.size();
	s = ' ' + s;
	vector pre(10, vector<int>(n + 1));
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= 6; j++)pre[j][i] = pre[j][i - 1];
		if(s[i] != 'U'){
			pre[s[i] - '0'][i]++;
		}else pre[6][i]++;
	}
	int ok = 1;
	for(int i = 10; i <= n; i++){
		if(pre[3][i] - pre[3][i - 10] == 10)ok = 0;
	}
	for(int i = 90; i <= n; i++){
		int d1 = pre[5][i] - pre[5][i - 90];
		int d2 = pre[6][i] - pre[6][i - 90];
		if(!d1 && !d2)ok = 0;
	}
	int last = -1;
	for(int i = 1; i <= n; i++){
		if(s[i] == '5'){
			//dbg(i, last);
			if(last != -1 && s[last] == '5') ok = 0;
			last = i;
		}else if(s[i] == 'U')last = i;
	}
	if(ok) cout << "valid\n";
	else cout << "invalid\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}