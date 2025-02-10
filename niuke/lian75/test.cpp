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
	int n;cin>>n;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	vector<int>tr(n+1);
	auto updata = [&](int x,int val)->void{
		while(x<=n){
			tr[x]+=val;
			x+=lowbit(x);
		}
	};
	auto ask = [&](int k)->int{
		int ans=0;
		int sum=0;
		int d=__lg(n);
		for(int i=d;i>=0;i--){
			int p=ans+(1<<i);
			if(p<=n&&sum+tr[p]<k){
				sum+=tr[p];
				ans=p;
			}
		}
		return ans+1;
	};
	for(int i=1;i<=n;i++)updata(i,1);
	int tot=n;
	int start=1;
	int d=0;
	for(int i=1;i<=n-1;i++){
		int k=(a[start]+d)%tot;
		if(k==0)k=tot;
		//dbg(i,k);
		int p=ask(k);
		updata(p,-1);
		tot--;
		k%=tot;
		if(k==0)k=tot;
		start=ask(k);
		d=k-1;
	}
	int ans=ask(1);
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