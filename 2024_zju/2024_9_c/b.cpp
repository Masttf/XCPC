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
	int n, d;cin >> n >> d;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	vector<int> s(n + 5);
	s[n + 1] = 1;
	for(int i = n; i >= 1; i--){
		int d = abs(s[i + 1] - 1 - a[i]);
		if(d <= s[i + 1]){
			s[i] = s[i + 1] + a[i];
		}else s[i] = s[i + 1];
	}
	int now=d;
	for(int i = 1; i <= n; i++){
		if(now >= s[i + 1])cout << 1;
		else cout << 0;
		now = min(now, abs(now - a[i]));
	}
	cout<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;//cin>>t;
	while(t--)solve();
	return 0;
}