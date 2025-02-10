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
	int n;cin>>n;
	vector<int>a(n+1);
	vector<int>pre(n+1);
	int ans=0;
	for(int i=1;i<=n;i++)cin>>a[i],pre[i]=pre[i-1]+a[i];
	
	for(int i=1;i<=n;i++){
		if(n%i!=0)continue;
		int mx=0;
		int mi=LONG_LONG_MAX;
		for(int j=1;j+i-1<=n;j+=i){
			mx=max(pre[j+i-1]-pre[j-1],mx);
			mi=min(pre[j+i-1]-pre[j-1],mi);
		}
		//dbg(i,mx,mi);
		ans=max(ans,mx-mi);
	}
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