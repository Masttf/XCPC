#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
	cout << #x << " -> "; \
	err(x); \
} while (0)

void err() {
	cout<<endl<<endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
	cout<<fixed<<setprecision(10)<<arg<< ' ';
	err(args...);
}
void solve(){
	int n,q;cin>>n>>q;
	for(int i=2;i<=n;i++){
		cout<<i-1<<' '<<i<<'\n';
	}
	int now=n-1;
	for(int i=1;i<=q;i++){
		int d;cin>>d;
		if(d==now)cout<<-1<<' '<<-1<<' '<<-1<<'\n';
		else{
			cout<<n<<' '<<now<<' '<<d<<'\n';
			now=d;
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