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
const int Max=1e18;
void solve(){
	int n,x;cin>>n>>x;
	int ans=-1;
	for(int i=0;i<=n;i++){
		int d=2*i-n;
		if(d==x){
			ans=i;
			break;
		}
	}
	if(ans==-1)cout<<-1<<'\n';
	else{
		cout<<ans<<' '<<n-ans<<'\n';
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}