#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n,m;cin>>n>>m;
	vector<int>a(n+1);
	vector<int>b(m+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	int res=0;
	for(int i=1;i<=m;i++)cin>>b[i],res|=b[i];
	if(n%2==1){
		int mi=0,mx=0;
		for(int i=1;i<=n;i++){
			mi^=a[i];
			mx^=a[i]|res;
		}
		cout<<mi<<' '<<mx<<'\n';
	}else{
		int mi=0,mx=0;
		for(int i=1;i<=n;i++){
			mx^=a[i];
			mi^=a[i]|res;
		}
		cout<<mi<<' '<<mx<<'\n';
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
