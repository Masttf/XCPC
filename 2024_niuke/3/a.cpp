#include<bits/stdc++.h>
#define int long long
#define lowbit(x) ((x)&-(x))
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
struct node{
	int val,tag;
};
void solve(){
	int n, l, r; cin >> n >> l >> r;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i++)cin >> a[i];
	int s = (n - r + r - l - 1) / (r - l);
	int sum = 0;
	for(int i = 0; i <= n; i++){
		sum += min((a[i] - 1) / 2, s);
	}
	if(sum >= s * l)cout << "Yes\n";
	else cout << "No\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}