#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=105;
int a[maxn];
int b[maxn];
bool vis[maxn];
void solve(){
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		b[i]=n+1-a[i];
	}
	for(int i=1;i<=n;i++)cout<<b[i]<<' ';
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
