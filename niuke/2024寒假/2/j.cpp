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
	sort(a.begin()+1,a.end());
	vector<int>pre(n+1);
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
	int ans=0;
	for(int i=1;i<=n;i++){
		int res=0;
		int p=upper_bound(a.begin()+1,a.end(),2*a[1])-a.begin();
		if(i>=p){
			res+=pre[p-1];
			res+=max((n-p),0ll)*2*a[1];
			res*=2;
		}else{
			res+=pre[i-1];
			res+=a[i]*(n-i);
			res*=2;
		}
		ans+=res;
		//dbg(i,ans,p);
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