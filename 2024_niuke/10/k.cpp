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
	vector<int>a, b;
	int ans = 0;
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		int x; cin >> x;
		if(x < 0)a.push_back(x);
		else if(x > 0)b.push_back(x);
		else cnt++;
	}
	ans = cnt;
	sort(a.begin(), a.end(), greater<>());
	sort(b.begin(), b.end());
	int sa = a.size(), sb = b.size();
	for(int i = 0; i < sb; i++){
		if(sb - i - 1 >= abs(b[i])){
			int res = i + 1;
			int l = 0, r = sa - 1;
			int res2 = -1;
			while(l <= r){
				int mid = (l + r) >> 1;
				int nd = abs(b[i]) + abs(a[mid]);
				//dbg(mid, a[mid], b[i],nd);
				if(sa - mid - 1 >= nd){
					res2 = mid;
					l = mid + 1;
				}else r = mid - 1;
			}
			res2++;
			//dbg(i, res, res2);
			ans = max(ans, res + res2 + cnt);
		}
	}
	swap(a, b);
	swap(sa, sb);
	for(int i = 0; i < sb; i++){
		if(sb - i - 1 >= abs(b[i])){
			int res = i + 1;
			int l = 0, r = sa - 1;
			int res2 = -1;
			while(l <= r){
				int mid = (l + r) >> 1;
				int nd = abs(b[i]) + abs(a[mid]);
				//dbg(mid, a[mid], b[i],nd);
				if(sa - mid - 1 >= nd){
					res2 = mid;
					l = mid + 1;
				}else r = mid - 1;
			}
			res2++;
			//dbg(i, res, res2);
			ans = max(ans, res + res2 + cnt);
		}
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