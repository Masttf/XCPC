#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
int a[maxn];
void solve(){
	int n,k;cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	int f=1;
	int cnt=0;
	for(int i=1;i<=n;i++){
		if((i-a[i])%k!=0){
			f=0;
			cnt++;
		}
	}
	if(f)cout<<0<<'\n';
	else if(cnt<=2)cout<<1<<'\n';
	else cout<<-1<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
