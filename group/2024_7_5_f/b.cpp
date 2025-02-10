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
	double s,a,b;cin>>s>>a>>b;
	double x=(a*b*(a+b)-b*b*(a+b))*s/(a*a*(a+b)-b*b*(a+b)+(a-b)*(b-a)*a);
	double res=x/b+(s-x)/a;
	cout<<fixed<<setprecision(6)<<res<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}