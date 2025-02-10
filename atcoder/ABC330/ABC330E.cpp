#include<bits/stdc++.h>
#define int long long
#define lowbit(x) ((x)&-(x))
using namespace std;
#define dbg(x...) \
do{ \
	cout<<#x<<" -> "; \
	err(x); \
}while(0)
void err(){
	cout<<endl;
}
template<class T,class ...Ts>
void err(T arg,Ts ...args){
	cout<<fixed<<setprecision(10)<<arg<<' ';
	err(args...);
}
void solve(){
	int n,q;cin>>n>>q;
	vector<int>a(n+1);
	//dbg("yes");
	for(int i=1;i<=n;i++)cin>>a[i];
	vector<int>t(n+1);
	vector<int>cnt(n+1);
	auto updata = [&](int x,int val)->void{
		while(x<=n){
			t[x]+=val;
			x+=lowbit(x);
		}
		return ;
	};

	auto ask = [&](int x)->int{
		int res=0;
		while(x){
			res+=t[x];
			x-=lowbit(x);
		}
		return res;
	};

	for(int i=1;i<=n;i++){
		if(a[i]<=n){
			//dbg(i,"yes");
			cnt[a[i]]++;
			if(cnt[a[i]]==1&&a[i])updata(a[i],1);
		}
	}
	//dbg("yes");
	for(int i=1;i<=q;i++){
		int p,x;cin>>p>>x;
		if(a[p]<=n){
			cnt[a[p]]--;
			if(!cnt[a[p]]&&a[p]){
				updata(a[p],-1);
			}
		}
		a[p]=x;
		if(x<=n){
			cnt[x]++;
			if(cnt[x]==1&&x){
				updata(a[p],1);
			}
		}
		if(!cnt[0])cout<<0<<'\n';
		else{
			int l=1,r=n;
			int res=0;
			while(l<=r){
				int mid=(l+r)>>1;
				if(ask(mid)==mid){
					res=mid;
					l=mid+1;
				}else r=mid-1;
			}
			cout<<res+1<<'\n';
		}
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