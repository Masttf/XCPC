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
	int n; cin >> n;
	vector<int>a(n + 1), b(n + 1);
	for(int i = 1; i <= n; i++)cin >> a[i];
	for(int i = 1; i <= n; i++)cin >> b[i];
	vector<int>cnt(n + 1);
	int ok1 = 0;
	int ok2 = 0;
	for(int i = 1; i <= n; i++){
		cnt[a[i]]++;
		if(cnt[a[i]] == 2)ok1 = 1;
	}
	cnt.assign(n + 1, 0);
	for(int i = 1; i <= n; i++){
		cnt[b[i]]++;
		if(cnt[b[i]] == 2)ok2 = 1;
	}
	if(!ok1 && !ok2){
		cout <<"sha7dow\n";
		return ;
	}
	cout << "shuishui\n";
	
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}