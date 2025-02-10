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
string res1 = "ava";
string res2 = "avava";
void solve(){
	string s; cin >> s;
	int ok = 1;
	int n = s.size();
	s = ' ' + s;
	for(int i = 1; i <= n; i++){
		if(i + 4 <= n){
			string temp = s.substr(i, 5);
			//dbg(temp, res2);
			if(temp == res2){
				i += 4;
				continue;
			}
		}
		if(i + 2 <= n){
			string temp = s.substr(i, 3);
			if(temp == res1){
				i += 2;
				continue;
			}
		}
		ok = 0;
	}
	if(ok)cout << "Yes\n";
	else cout << "No\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}