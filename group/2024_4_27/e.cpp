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
	int n;cin >> n;
	string s;cin >> s;
	vector<int>r;
	int len = s.size();
	for (int i = 0;i < len;i++) {
		if (s[i] == ')') r.push_back(i);
	}
	int cnt = 0,ans = 0;
	int lenr = r.size();
	int now = 0;
	for (int i = 0;i < len;i++) {
		if (s[i] == '?') {
			continue;
		}
		else if (s[i] == '(') {
			while (cnt < lenr && r[cnt] < i) cnt++;
			if (cnt == lenr) break;
			cnt++;
			ans += 2;
		}	
		else {
			if (r[cnt] > i) {
				continue;
			}
			while (cnt < lenr && r[cnt] < i) cnt++;
			cnt++;
		}
		if (cnt == lenr) break;
		//dbg(ans,cnt,i);
	}
	cout << ans << '\n';
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}