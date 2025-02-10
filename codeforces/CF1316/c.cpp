#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n,m,p;cin>>n>>m>>p;
	vector<int>a(n+1),b(m+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++)cin>>b[i];
	int p1=0,p2=0;
	for(int i=1;i<=n;i++){
		if(a[i]%p!=0){
			p1=i-1;
			break;
		}
	}
	for(int i=1;i<=m;i++){
		if(b[i]%p!=0){
			p2=i-1;
			break;
		}
	}
	cout<<p1+p2<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;//cin>>t;
	while(t--)solve();
	return 0;
}