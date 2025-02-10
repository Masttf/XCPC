#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e3+5;
int a[maxn][maxn];
void solve(){
	int n,k;cin>>n>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)cin>>a[i][j];
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i][j]!=a[n-i+1][n-j+1]){
				//cout<<i<<' '<<j<<'\n';
				cnt++;
			}
		}
	}
	cnt/=2;
	if(n%2!=0){
		if(cnt>k)cout<<"NO\n";
		else cout<<"YES\n";
	}else{
		if(cnt>k||(cnt-k)%2!=0)cout<<"NO\n";
		else cout<<"YES\n";
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
