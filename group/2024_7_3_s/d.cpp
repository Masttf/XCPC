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
	int n;cin>>n;
	vector<int>h(n+1),l(n+1),r(n+1);
	for(int i=1;i<=n;i++)cin>>h[i]>>l[i]>>r[i];
	for(int i=1;i<=n;i++){
		int ans1=0;
		int ans2=0;
		for(int j=1;j<=n;j++){
			if(h[i]<=h[j])continue;
			if(l[j]<l[i]&&l[i]<r[j]){
				if(h[ans1]<h[j])ans1=j;
			}
			if(l[j]<r[i]&&r[i]<r[j]){
				if(h[ans2]<h[j])ans2=j;
			}
		}
		cout<<ans1<<' '<<ans2<<'\n';
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