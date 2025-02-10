#include<bits/stdc++.h>
#define int long long
#define lowbit(x) ((x)&-(x))
using namespace std;
void solve(){
	int n,m;cin>>n>>m;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	int ans=-1;
	vector<int>cnt(m+1);
	vector<int>t(n+1);
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
		if(cnt[a[i]]){
			updata(cnt[a[i]],-1);
			updata(i,1);
		}else{
			updata(i,1);
		}
		cnt[a[i]]=i;
		ans=max(ans,ask(i)-ask(cnt[1])-1);
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