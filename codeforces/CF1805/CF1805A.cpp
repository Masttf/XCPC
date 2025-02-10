#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e3+5;
int a[maxn];
void solve(){
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	int x=0;
	for(int i=1;i<=n;i++)x^=a[i];
	if(x==0)cout<<0<<'\n';
	else if(n%2!=0)cout<<x<<'\n';
	else cout<<-1<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}
