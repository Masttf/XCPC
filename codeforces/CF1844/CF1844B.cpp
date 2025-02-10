#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
int ans[maxn];
void solve(){
	int n;cin>>n;
	if(n==1){
		cout<<1<<'\n';
		return ;
	}
	if(n==2){
		cout<<2<<' '<<1<<'\n';
		return ;
	}
	ans[(n+1)/2]=1;
	ans[1]=3;
	ans[n]=2;
	int p=4;
	for(int i=2;i<=n-1;i++){
		if(i!=(n+1)/2)ans[i]=p,p++;
	}
	for(int i=1;i<=n;i++)cout<<ans[i]<<' ';
	cout<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}
