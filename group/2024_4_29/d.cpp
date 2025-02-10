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
void solve(){
	int n,m;cin>>n>>m;
	vector<unsigned long long>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	vector<unsigned long long>b(m+1);
	for(int i=1;i<=m;i++)cin>>b[i];
	unsigned long long ans=0;
	int len=0;
	int i=1;
	for(int j=1;j<=m;j++){
		if(a[i]<b[j]){
			ans^=len;
			len=0;
			while(i<=n&&a[i]<b[j])i++;
		}
		if(b[j]==a[i]){
			len++;
		}
	}
	ans^=len;
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