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
	for(int i=1;i<=n;i++)cin>>a[i];
	vector<int>res1(n+1);
	int now=1;
	for(int i=1;i<=n;i++){
		if(a[i]<now){
			res1[i]=a[i];
			now=a[i];
		}else res1[i]=now;
		now++;
	}
	now=1;
	for(int i=n;i>=1;i--){
		if(a[i]<now){
			res1[i]=min(res1[i],a[i]);
			now=a[i];
		}else res1[i]=min(res1[i],now);
		now++;
	}
	int ans=0;
	for(int i=1;i<=n;i++)ans=max(ans,res1[i]);
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	while(t--)solve();
	return 0;
}