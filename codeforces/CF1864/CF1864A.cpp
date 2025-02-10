#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int x,y,n;cin>>x>>y>>n;
	vector<int>a(n+1);
	a[n]=y;
	int d=1;
	for(int i=n-1;i>=1;i--){
		a[i]=a[i+1]-d;
		d++;
	}
	if(a[1]>=x){
		cout<<x<<' ';
		for(int i=2;i<=n;i++)cout<<a[i]<<' ';
		cout<<'\n';
	}else cout<<-1<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
