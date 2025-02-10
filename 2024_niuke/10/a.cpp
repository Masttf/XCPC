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
	int cnt = 0;
	int cnt1 = 0;
	for(auto x : s){
		if(x =='Y')cnt++;
		if(x == 'N')cnt1++;
	}
	if(cnt >= 4){
		cout << 1 <<'\n';
		return ;
	}
	if(cnt1 >= 2){
		cout << -1 << '\n';
		return ;
	}
	cout << 0 << '\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}