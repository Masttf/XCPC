#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+5;
int a[maxn];
void solve(){
	int n,m,k;cin>>n>>m>>k;//思考什么样不成立
	int t=(n+k-1)/k;
	for(int i=1;i<=m;i++)cin>>a[i];
	int cnt=0,f=1;
	for(int i=1;i<=m;i++){
		if(a[i]>t)f=0;//大于最大
		else if(a[i]==t)cnt++;
	}
	int d=n%k;
	if(!d)d=k;
	if(f==0||cnt>d)cout<<"no\n";
	else cout<<"yes\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
