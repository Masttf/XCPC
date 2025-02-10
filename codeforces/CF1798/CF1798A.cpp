#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=105;
int a[maxn],b[maxn];
void solve(){
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	for(int i=1;i<=n;i++){
		if(a[i]<b[i])swap(a[i],b[i]);
	}
	int m1=0,m2=0;
	for(int i=1;i<=n;i++){
		m1=max(m1,a[i]);
		m2=max(m2,b[i]);
	}
	if(m1==a[n]&&m2==b[n])cout<<"YES\n";
	else cout<<"NO\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
