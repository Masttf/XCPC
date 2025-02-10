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
struct node{
	int l,r;
};
bool cmp1(node x,node y){
	if(x.l!=y.l)return x.l<y.l;
	return x.r<y.r;
}
bool cmp2(node x,node y){
	if(x.r!=y.r)return x.r<y.r;
	return x.l<y.l;
}
const int mod=998244353;
void solve(){
	int n;cin>>n;
	vector<node>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i].l>>a[i].r;
	if(n==1){
		cout<<0<<'\n';
		return ;
	}
	vector<int>f(n+1);
	f[0]=1;
	for(int i=1;i<=n;i++)f[i]=f[i-1]*i%mod;
	int ans=f[n];
	sort(a.begin()+1,a.end(),cmp1);
	int res1=1;
	for(int i=1;i<=n;i++){
		int j=i;
		while(j<=n&&a[j].l==a[i].l)j++;
		res1=res1*f[j-i]%mod;
		i=j-1;
	}
	ans-=res1;
	//dbg(ans);
	int ok=1;
	for(int i=2;i<=n;i++){
		if(a[i].r<a[i-1].r)ok=0;
	}
	if(ok){
		int res=1;
		for(int i=1;i<=n;i++){
			int j=i;
			while(j<=n&&a[i].l==a[j].l&&a[i].r==a[j].r)j++;
			res=res*f[j-i]%mod;
			i=j-1;
		}
		ans+=res;
	}
	//dbg(ans);
	sort(a.begin()+1,a.end(),cmp2);
	int res2=1;
	for(int i=1;i<=n;i++){
		int j=i;
		while(j<=n&&a[i].r==a[j].r)j++;
		res2=res2*f[j-i]%mod;
		i=j-1;
	}
	ans-=res2;
	//dbg(ans);
	ans%=mod;
	if(ans<0)ans+=mod;
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;//cin>>t;
	while(t--)solve();
	return 0;
}