#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=3e5+5;
int a[maxn];
void solve(){
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n==1){
		cout<<1<<'\n';
		return ;
	}
	if(n==2){
		if(a[1]==a[2])cout<<1<<'\n';
		else cout<<2<<'\n';
		return ;
	}
	int flag=1;
	for(int i=2;i<=n;i++){
		if(a[i]!=a[1])flag=0;
	}
	if(flag)cout<<1<<'\n';
	else{
		int ans=n;
		int t=-1;
		for(int i=2;i<=n;i++){
			if(a[i]==a[i-1]){
				ans--;
				continue;
			}
			if(t==-1){
				if(a[i]>a[i-1])t=1;
				else t=0;
			}else{
				if(a[i]>a[i-1]&&t)ans--;
				else if(a[i]>a[i-1])t=1;
				else if(a[i]<a[i-1]&&!t)ans--;
				else if(a[i]<a[i-1])t=0;
			}
		}
		cout<<ans<<'\n';
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
