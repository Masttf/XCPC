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
	int n,m,l;cin>>n;
	vector<int>a(n+1);
	set<int>s;
	for(int i=1;i<=n;i++)cin>>a[i];
	cin>>m;
	vector<int>b(m+1);
	for(int i=1;i<=m;i++)cin>>b[i];
	cin>>l;
	vector<int>c(l+1);
	for(int i=1;i<=l;i++)cin>>c[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(int k=1;k<=l;k++){
				s.insert(a[i]+b[j]+c[k]);
			}
		}
	}
	int q;cin>>q;
	for(int i=1;i<=q;i++){
		int x;cin>>x;
		if(s.count(x))cout<<"Yes\n";
		else cout<<"No\n";
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