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
void err(T arg, Ts &... args) {
	cout<<fixed<<setprecision(10)<<arg<< ' ';
	err(args...);
}
void solve(){
	int n,m,u;cin>>n>>m>>u;
	vector<int>a(n+1);
	vector<int>b(n+1);
	vector<int>prea(n+1);
	vector<int>preb(n+1);
	for(int i=1;i<=n;i++)cin>>a[i],prea[i]=prea[i-1]+a[i];
	for(int i=1;i<=n;i++)cin>>b[i],preb[i]=preb[i-1]+b[i];
	int ans=0;
	
	for(int i=1;i<=n;i++){
		int mx=0;
		int sum=0;
		int cnt=0;
		for(int j=i;j<=n;j++){
			mx+=a[j];
			sum+=b[j];
			if(mx<=m&&sum<=u)cnt++;
			else break;
		}
		ans=max(ans,cnt);
	}
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}