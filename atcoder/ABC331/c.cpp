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
	vector<int>b(n+1);
	for(int i=1;i<=n;i++)cin>>a[i],b[i]=a[i];
	vector<int>pre(n+1);
	//vector<int>ans(n+1);
	sort(b.begin()+1,b.end());
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+b[i];
	for(int i=1;i<=n;i++){
		int p=upper_bound(b.begin()+1,b.end(),a[i])-b.begin()-1;
		cout<<pre[n]-pre[p]<<' ';
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	while(t--)solve();
	return 0;
}