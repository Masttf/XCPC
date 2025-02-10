#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	vector<int>pre(n+1);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1];
		if(i%2==1)pre[i]+=a[i];
		else pre[i]-=a[i];
	}
	map<int,int>m;
	m[0]=1;
	for(int i=1;i<=n;i++){
		if(m.count(pre[i])){
			cout<<"Yes\n";
			return ;
		}
		m[pre[i]]=1;
	}
	cout<<"No\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}