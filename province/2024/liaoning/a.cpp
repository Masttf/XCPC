#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
cout << #x << " -> "; \
err(x); \
} while (0)

void err() {
	cout << endl << endl;
}

template<class T, class... Ts>
void err(T arg, Ts ... args) {
	cout << fixed << setprecision(10) << arg << ' ';
	err(args...);
}
void solve(){
	string s;
	getline(cin, s);
//	cout << s << endl;
	int n; cin >> n;
//	dbg(n);
	set<string> st;
	for(int i = 1; i <= n; i++){
		string t; cin >> t;
		st.insert(t);
	}
	string res = "";
	int ans = 0;
	for(auto x : s){
		if(x == ' ' || x == ',' || x == '.' || x ==  '!' || x == '?'){
//			dbg(res);
			if(!res.empty()){
				if(!st.count(res))ans++;
			}
			st.insert(res);
			res = "";
		}else{
			if(x >= 'A' && x <= 'Z'){
				res += x - 'A' + 'a';
			}else res += x;
		}
	}
	cout << ans << '\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	// cin >> t;
	while(t--)solve();
	return 0;
}