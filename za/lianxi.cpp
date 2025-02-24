#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n,x;cin>>n>>x;
	vector<int>a(n+1);
	vector<int>cnt(n+5);
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=n;i>=1;i--){
		cnt[i]+=a[i];
		cnt[min(n+1,i+x)]-=a[i];
	}
	for(int i=1;i<=n;i++)cnt[i]+=cnt[i-1];
	int mx=1;
	for(int i=2;i<=n;i++){
		int d=cnt[mx]-cnt[i];
		if(d>0){
			if(d<=30){
				int res1=a[mx]*(1LL<<d);
				int res2=a[i];
				if(res1<res2)mx=i;
			}
		}else{
			d=-d;
			if(d>30)mx=i;
			else{
				int res1=a[mx];
				int res2=a[i]*(1ll<<d);
				if(res1<res2)mx=i;
			}
		}
	}
	//cout<<a[39]<<' '<<cnt[39]<<'\n';
	//cout<<a[1097]<<' '<<cnt[1097]<<'\n';
	cout<<mx<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}
