#include<bits/stdc++.h>
#define lowbit(x) ((x)&-(x))
#define int long long
using namespace std;
const int mod=998244353;
int qmi(int a,int b){
	int res=1;
	while(b){
		if(b&1)res=res*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return res;
}
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
	int n,k;cin>>n>>k;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	vector<int>b(k+1);
	for(int i=1;i<=k;i++)cin>>b[i],b[i]++;
	//k++;
	int target=k;
	vector<int>t(k+1);
	auto updata = [&](int x)->void{
		while(x<=target){
			t[x]++;
			x+=lowbit(x);
		}
	};
	auto ask = [&](int x)->int{
		int res=0;
		while(x){
			res+=t[x];
			x-=lowbit(x);
		}
		return res;
	};
	int ans=0;
	for(int i=k;i>=1;i--){
		updata(b[i]);
		ans+=ask(b[i]-1);
	}
	ans=ans*n%mod;//把对其他数的值维护转移到自己身上 然后统计的是a 多少次方的贡献
	int all=(k+1)*k/2;
	for(int i=0;i<=20&&i<k;i++){
		all-=(k-i);
	}
	//dbg(all);
	target=2*n;
	t.assign(2*n+1,0);
	for(int i=n;i>=1;i--){
		for(int d=-20;d<=20;d++){
			if(abs(d)>=k)continue;
			int v;
			if(d<0)v=a[i]>>(-d);
			else v=a[i]<<d;
			if(v>2*n)v=2*n;
			ans+=ask(v)*(k-abs(d))%mod;
			if(ans>=mod)ans-=mod;
		}
		ans+=ask(2*n)*all%mod;
		if(ans>=mod)ans-=mod;
		updata(a[i]);
		//dbg(ans);	
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