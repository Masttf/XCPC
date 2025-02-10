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
	int n,k;cin>>n>>k;
	vector<int>x(n+1);
	vector<int>y(n+1);
	for(int i=1;i<=n;i++)cin>>x[i]>>y[i];
	sort(x.begin()+1,x.end());
	sort(y.begin()+1,y.end());
	int ans=max(x[n]-x[1],y[n]-y[1]);
	int l=0,r=ans;
	auto get = [&](vector<int>&t,int d)->int{
		int res=0;
		int mi=t[1];
		int mx=t[n];
		int l=1,r=n;
		int cnt1=0;
		int cnt2=0;
		while(mx-mi>d){
			while(l<=n&&t[l]==mi)l++,cnt1++;
			while(r>=1&&t[r]==mx)r--,cnt2++;
			if(cnt1<=cnt2){
				if(mx-t[l]<=d){
					res+=(mx-mi-d)*cnt1;
				}else res+=(t[l]-mi)*cnt1;
				mi=t[l];
			}else{
				if(t[r]-mi<=d){
					res+=(mx-mi-d)*cnt2;
				}else res+=(mx-t[r])*cnt2;
				mx=t[r];
			}
		}
		return res;
	};
	auto check = [&](int d)->bool{
		int res=get(x,d)+get(y,d);
		return res<=k;
	};
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			r=mid-1;
		}else l=mid+1;
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