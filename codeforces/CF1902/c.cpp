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
	map<int,int>m;
	for(int i=1;i<=n;i++)cin>>a[i],m[a[i]]=1;
	if(n==1){
		cout<<1<<'\n';
		return ;
	}
	sort(a.begin()+1,a.end());
	int cnt=0;
	int res=0;
	for(int i=1;i<=n;i++){
		cnt+=a[n]-a[i];
		res=__gcd(res,a[n]-a[i]);
	}
	int ans=cnt/res+n;
	int now=a[n]-res;
	while(m.count(now)){
		now-=res;
	}
	ans=min(ans,cnt/res+(a[n]-now)/res);
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