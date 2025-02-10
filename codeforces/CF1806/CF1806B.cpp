#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
int a[maxn];
void solve(){
	int n;cin>>n;
	int cnt=0,mx=0,c2=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(!a[i])cnt++;
		else if(a[i]==1)c2++;
		mx=max(a[i],mx);
	}
	if(n-cnt>=cnt-1)cout<<0<<'\n';
	else{
		if(cnt==n)cout<<1<<'\n';
		else if(mx==1){//1shizuida
			if(c2>cnt+1)cout<<3<<'\n';
			else cout<<2<<'\n';
		}else cout<<1<<'\n';
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
