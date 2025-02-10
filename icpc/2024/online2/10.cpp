#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do{ \
	cout << #x << " -> "; \
	err(x); \
}while(0)
void err(){
	cout << endl << endl;
}
template<class T, class ...Ts>
void err(T arg, Ts ...args){
	cout << fixed << setprecision(10) << arg << ' ';
	err(args...);
}
struct node{
	int w, v, c;
	bool operator < (const node &y)const{
		return c * y.w < w * y.c;
	}
};
void solve(){
	int n; cin >> n;
	vector<node>a(n + 1);
	int sumw = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i].w >> a[i].v >> a[i].c;
		//sumw += a[i].w;
	}
	sort(a.begin() + 1, a.end());
	int ans = 0;
	int sum = 0;
	for(int i = 1; i <= n; i++){
		//dbg(a[i].c, a[i].w);
		
		ans += a[i].v;
		ans -= sumw * a[i].c;
		sumw += a[i].w;
	}
	cout << ans << '\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	while(t--)solve();
	//cin >> t;
	return 0;
}