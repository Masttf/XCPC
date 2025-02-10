#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=105;
int a[maxn];
void solve(){
	int n;cin>>n;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<0)cnt++;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(i>n-cnt){
			ans--;
			cout<<ans<<' ';
		}else{
			ans++;
			cout<<ans<<' ';
		}
	}
	cout<<'\n';
	for(int i=1;i<=cnt;i++){
		cout<<1<<' '<<0<<' ';
	}
	ans=0;
	for(int i=2*cnt+1;i<=n;i++){
		ans++;
		cout<<ans<<' ';
	}
	cout<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
