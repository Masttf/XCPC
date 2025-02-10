#include<bits/stdc++.h>
//#define int long long
using namespace std;
#define dbg(x...) \
do{ \
	cout<<#x<<" -> "; \
	err(x); \
}while(0)
void err(){
	cout<<endl<<endl;
}
template<class T,class ...Ts>
void err(T arg,Ts ...args){
	cout<<fixed<<setprecision(10)<<arg<<' ';
	err(args...);
}
const int maxn=987654321;
const long long Max=1e18;
void solve(){
	int n,k;cin>>n>>k;
	vector<int>a(n+1),p(n+1);
	int mx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	for(int i=1;i<=n;i++)cin>>p[i];
	vector<long long>pre(n+1);
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
	vector<vector<int>>tr(2,vector<int>(n*35));
	vector<long long>mi(n*35,Max);
	int tot=1;
	auto insert = [&](int x,long long val)->void{
		int pp=1;
		for(int i=31;i>=0;i--){
			int d=(x>>i)&1;
			if(!tr[d][pp]){
				tr[d][pp]=++tot;
			}
			pp=tr[d][pp];
			mi[pp]=min(mi[pp],val);
		}
	};
	auto ask = [&](int x,long long val)->bool{
		int pp=1;
		for(int i=31;i>=0;i--){
			int d1=(x>>i)&1;
			int d2=(k>>i)&1;
			if(d2==1){
				pp=tr[1^d1][pp];
			}else{
				if(tr[1^d1][pp]){
					if(val>=mi[tr[1^d1][pp]])return true;
				}
				pp=tr[d1][pp];
			}
		}
		return val>=mi[pp];
	};
	auto check = [&](int kk)->bool{
		tot=1;
		tr=vector<vector<int>>(2,vector<int>(n*35));
		mi=vector<long long>(n*35,Max);
		for(int i=1;i<=n;i++){
			//dbg(i,pre[i-1]+kk*(1-i));
			insert(p[i],1ll*pre[i-1]+1ll*kk*(1-i));
			//dbg("yes");
			bool ok=ask(p[i],1ll*pre[i]-1ll*kk*i);
			if(ok)return true;
		}
		return false;
	};
	int l=0,r=mx;
	int ans=-1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else r=mid-1;
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