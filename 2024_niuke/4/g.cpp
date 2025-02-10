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
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	auto get_dis = [&](int x,int y,int z, int p) -> double{
		return sqrt((x - z)*(x - z) + (y - p) * (y - p));	
	};
	double ans = min({get_dis(x1, -y1, x2, y2), get_dis(-x1, y1,x2,y2),get_dis(x1,y1,-x2,y2),get_dis(x1,y1,x2,-y2)});
	cout <<fixed << setprecision(10) << ans << '\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}