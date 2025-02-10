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
	int n,m;cin>>n>>m;
	vector<int>a(m+1);
	for(int i=1;i<=m;i++)cin>>a[i];
	int ok=1;
	int len=0;
	for(int i=1;i<=m;i++){
		if(i+a[i]-1>n)ok=0;
		len+=a[i];
	}
	if(!ok||len<n)cout<<-1<<'\n';
	else{
		vector<int>ans(m+1);
		for(int i=1;i<=m;i++)ans[i]=i;
		vector<int>suf(n+5);
		for(int i=m;i>=1;i--)suf[i]=suf[i+1]+a[i];
		for(int i=1;i<=m;i++){
			if(i+suf[i]-1<=n)ans[i]=n-suf[i]+1;
			else ans[i]=i;
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<" \n"[i==m];
		}
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