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
	int ans=0;
	auto get = [&](int l,int r)->void{
		if(l+1==r){
			ans+=min(a[l],a[r]);
			return ;
		}
		//dbg(l,r);
		int mi=0;
		int cnt=0;
		for(int i=l+1;i<r;i++){
			if(i%2==1)cnt+=a[i];
			else cnt-=a[i];
			mi=min(mi,cnt);
		}
		mi=-mi;
		int d1=cnt+mi;
		int d2=a[r]-d1+1;
		int d3=a[l]-mi+1;
		ans+=max(0ll,min(d2,d3));
	};
	for(int len=2;len<=n;len+=2){
		for(int i=1;i+len-1<=n;i+=2){
			get(i,i+len-1);
			//dbg(len,i,ans);
		}
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