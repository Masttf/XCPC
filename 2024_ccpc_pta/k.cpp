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
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i++) cin >> a[i];
	vector<set<int>> bl(100);
	for(int i = 1; i <= n; i++){
		for(int j = 64; j >= 0; j--){
			if(a[i] >> j & 1)bl[j].insert(i);
		}
	}
	int ok = 1;
	vector<pair<int, int>>res;
	while(1){
		int f = 0;
		int cnt = 0;
		for(int i = 0; i <= 64; i++){
			if(f)break;
			if(bl[i].size() == 2){
				f = 1;
				auto it = bl[i].begin();
				int x = *it;
				it++;
				int y = *it;
				bl[i].clear();
				int c = a[x] & a[y];
				a[x] -= c;
				a[y] -= c;
				res.push_back({x, c});
				for(int j = 64; j >= 0; j--){
					if(c >> j & 1){
						bl[j].erase(x);
						bl[j].erase(y);
					}
				}
				break;
			}
			if(!bl[i].empty())cnt++;
		}
		if(!f){
			if(cnt){
				ok = 0;
			}
			break;
		}
	}
	if(!ok)cout << -1 << '\n';
	else{
		cout << res.size() << '\n';
		for(auto [x, y] : res){
			cout << x << ' ' << y << '\n';
		}
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