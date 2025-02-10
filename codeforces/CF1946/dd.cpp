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
	int n,m;cin>>n>>m;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	int ans=-1;
	auto get = [&](int gl,int bit)->void{
		vector<int>pre(n+1);
		for(int i=1;i<=n;i++){
			pre[i]=pre[i-1]^(a[i]>>bit);
		}
		if((pre[n]&gl)!=pre[n])return ;
		int cnt=0;
		for(int i=1;i<=n;i++){
			if((pre[i]&gl)==pre[i])cnt++;
		}
		ans=max(ans,cnt);
	};
	for(int i=30;i>=0;i--){
		if(m>>i&1){
			int d=(m>>i)-1;
			get(d,i);
		}
	}
	get(m,0);
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}