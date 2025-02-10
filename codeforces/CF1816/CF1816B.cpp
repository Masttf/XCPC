#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+5;
int a[3][maxn];
void solve(){
	int n;cin>>n;
	int f=2;
	for(int i=1;i<=n;i++){
		a[f][i]=i;
		f=3-f;
	}
	a[1][1]=2*n;
	f=2;
	for(int i=2,j=n+1;i<=n;i++,j++){
		a[f][i]=j;
		f=3-f;
	}
	for(int i=1;i<=2;i++){
		for(int j=1;j<=n;j++)cout<<a[i][j]<<' ';
		cout<<'\n';
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t ;cin>>t;
	while(t--)solve();
	return 0;
}
